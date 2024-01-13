package book_keeper

type PhiloEventType int

const (
	Eating PhiloEventType = iota
	Sleeping
	Thinking
	HoldingFork
	Dead
	Unknown
)

var eventDesc = map[PhiloEventType]string{
	Eating:      "is eating",
	Sleeping:    "is sleeping",
	Thinking:    "is thinking",
	HoldingFork: "has taken a fork",
	Dead:        "died",
	Unknown:     "unknown event",
}

type PhiloEvent struct {
	Timestamp int64
	Type      PhiloEventType
}

type PhiloStatus struct {
	Events   []PhiloEvent
	LastMeal int64
	NMeals   int
}

func (e PhiloEventType) String() string {
	if desc, ok := eventDesc[e]; ok {
		return desc
	}
	return eventDesc[Unknown]
}

func GetPhiloEventType(desc string) PhiloEventType {
	for k, v := range eventDesc {
		if v == desc {
			return k
		}
	}
	return Unknown
}
