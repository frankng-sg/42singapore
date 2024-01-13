package book_keeper

import "errors"

const DeathNoticeLatency = 10 // in milliseconds

type BookKeeper struct {
	Forks              []ForkStatus
	Philos             []PhiloStatus
	DeathNoticeLatency int
	T2Live             int
	T2Eat              int
	T2Sleep            int
	NPhilos            int
	NMeals             int
	DeathHappened      bool
}

func NewBookKeeper(NPhilos, T2Live, T2Eat, T2Sleep, NMeals int) *BookKeeper {
	keeper := &BookKeeper{
		Forks:              make([]ForkStatus, NPhilos+1),
		Philos:             make([]PhiloStatus, NPhilos+1),
		DeathNoticeLatency: DeathNoticeLatency,
		T2Live:             T2Live,
		T2Eat:              T2Eat,
		T2Sleep:            T2Sleep,
		NPhilos:            NPhilos,
		NMeals:             NMeals,
	}
	keeper.Forks[0] = Taken
	return keeper
}

func validateFork(philoId int, forks []ForkStatus) error {
	var leftForkId, rightForkId int

	leftForkId, rightForkId = philoId-1, philoId+1
	if philoId <= 0 {
		leftForkId = len(forks) - 1
	} else if philoId >= len(forks)-1 {
		rightForkId = 1
	}

	if forks[leftForkId] != Available && forks[rightForkId] != Available {
		return errors.New("fork is not available")
	}
	return nil
}

func grabFork(philoId int, forks []ForkStatus) {
	var leftForkId, rightForkId int

	leftForkId, rightForkId = philoId-1, philoId+1
	if philoId <= 0 {
		leftForkId = len(forks) - 1
	} else if philoId >= len(forks)-1 {
		rightForkId = 1
	}

	if forks[leftForkId] == Available {
		forks[leftForkId] = Taken
	} else if forks[rightForkId] == Available {
		forks[rightForkId] = Taken
	}
}

func validateEvent(b *BookKeeper, philoId int, e PhiloEvent) error {
	if (philoId <= 0) || (philoId > b.NPhilos) {
		return errors.New("invalid philosopher ID")
	}
	if e.Type != Dead && e.Timestamp > int64(b.T2Live)+b.Philos[philoId].LastMeal {
		return errors.New("philosopher is dead")
	}
	events := &b.Philos[philoId].Events
	nEvents := len(*events)
	if nEvents > 0 && e.Timestamp < (*events)[nEvents-1].Timestamp {
		return errors.New("event timestamp is incorrect")
	}
	switch e.Type {
	case Eating:
		if nEvents < 2 || (*events)[nEvents-1].Type != HoldingFork ||
			(*events)[nEvents-2].Type != HoldingFork {
			return errors.New("philosopher does not hold two forks before eating")
		}
		if b.Philos[philoId].NMeals < 0 {
			return errors.New("philosopher has exceeded number of allowed meals")
		}
	case HoldingFork:
		holdingForkEvents := 0
		for i := nEvents - 1; i >= 0 && (*events)[i].Type != Eating; i-- {
			if (*events)[i].Type == HoldingFork {
				holdingForkEvents++
			}
		}
		if holdingForkEvents > 1 {
			return errors.New("philosopher is holding more than two forks")
		}
		if nEvents >= 1 && (*events)[nEvents-1].Type != HoldingFork && holdingForkEvents > 0 {
			return errors.New("philosopher is doing something else while picking up forks to eat")
		}
		if err := validateFork(philoId, b.Forks); err != nil {
			return err
		}
		grabFork(philoId, b.Forks)
	case Sleeping:
		if nEvents < 1 || (*events)[nEvents-1].Type != Eating {
			return errors.New("philosopher does not before sleeping")
		}
	case Dead:
		if e.Timestamp > int64(b.T2Live)+b.Philos[philoId].LastMeal+int64(b.DeathNoticeLatency) {
			return errors.New("philosopher 's death notice is too late")
		}
	default:
	}
	return nil
}

func (b *BookKeeper) Add(philoId int, e PhiloEvent) error {
	if err := validateEvent(b, philoId, e); err != nil {
		return err
	}
	b.Philos[philoId].Events = append(b.Philos[philoId].Events, e)
	if e.Type == Eating {
		b.Philos[philoId].LastMeal = e.Timestamp
		b.Philos[philoId].NMeals--
	}
	return nil
}

func (b *BookKeeper) Finalize() error {
	cntDeath := 0
	for i := 1; i <= b.NPhilos; i++ {
		p := b.Philos[i]
		if p.NMeals > 0 {
			return errors.New("philosopher has not eaten enough meals")
		}
		if len(p.Events) > 0 && p.Events[len(p.Events)-1].Type != Eating && p.Events[len(p.Events)-1].Type != Dead {
			return errors.New("philosopher is not eating or dying at the end")
		}

		for i := len(p.Events) - 1; i >= 0; i-- {
			if p.Events[i].Type == Dead {
				if i != len(p.Events)-1 {
					return errors.New("philosopher is still active after death")
				}
				cntDeath += 1
			}
		}
	}
	if cntDeath > 1 {
		return errors.New("simulation does not stop right after a philosopher dies")
	} else if cntDeath == 1 {
		b.DeathHappened = true
	}
	return nil
}
