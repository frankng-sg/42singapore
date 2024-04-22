#include "philo.h"

static void philo_say(t_philo *philo, char *action) {
  pthread_mutex_lock(&philo->shared->print_lock);
  printf("%ld %d %s\n", sim_time(philo), philo->id + 1, action);
  pthread_mutex_unlock(&philo->shared->print_lock);
}

static void philo_eat(t_philo *philo) {
  philo_say(philo, FORK);
  philo_say(philo, FORK);
  philo_say(philo, EATING);
  philo->meals++;
  philo->last_meal = sim_time(philo);
  philo->dead_at = philo->last_meal + philo->shared->params.t2live;
  if (philo->shared->params.meals > 0 &&
      philo->meals >= philo->shared->params.meals)
    params_set_wellfed(&philo->shared->params);
  ft_msleep(philo, philo->shared->params.t2eat);
  philo->state = READY_SLEEP;
}

static void philo_sleep(t_philo *philo) {
  fork_drop(&philo->shared->forks, philo->id);
  philo_say(philo, SLEEPING);
  ft_msleep(philo, philo->shared->params.t2sleep);
  philo->state = READY_THINK;
}

static void philo_think(t_philo *philo) {
  if (philo->state == READY_THINK) {
    philo_say(philo, THINKING);
    philo->state = READY_EAT;
  }
}

void *philo_routine(void *philo) {
  t_philo *p;

  p = (t_philo *)philo;
  while (!params_get_ready(&p->shared->params))
    ;
  while (!params_get_ended(&p->shared->params)) {
    if (sim_time(p) > p->dead_at)
      break;
    if (p->state == ALLOWED_EAT)
      philo_eat(p);
    else if (p->state == READY_SLEEP)
      philo_sleep(p);
    else
      philo_think(p);
  }
  if (!params_get_ended(&p->shared->params)) {
    params_set_ended(&p->shared->params);
    philo_say(p, DIED);
  }
  return (NULL);
}
