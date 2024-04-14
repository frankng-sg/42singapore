#include "philo.h"

static void philo_say(t_philo *philo, char *action) {
  time_t at_time;

  pthread_mutex_lock(&philo->shared->print_lock);
  at_time = time_since(philo->params->started_at);
  printf("%ld %d %s\n", at_time, philo->id + 1, action);
  pthread_mutex_unlock(&philo->shared->print_lock);
}

static void philo_eat(t_philo *philo) {
  time_t t2eat;
  time_t t2live;

  t2eat = philo->shared->params->t2eat;
  t2live = philo->shared->params->t2live;
  philo_say(philo, FORK);
  philo->last_meal = sim_time(philo->shared->params);
  philo_say(philo, EATING);
  philo->meals++;
  ft_msleep(philo, philo->shared->params->t2eat);
  fork_drop(philo->shared->forks, philo->id);
  philo->state = READY_SLEEP;
}

static void philo_sleep(t_philo *philo) {
  philo_say(philo, SLEEPING);
  ft_msleep(philo, philo->shared->params->t2sleep);
  philo->state = READY_EAT;
}

static void philo_checkup(t_philo *philo) {
  time_t t2eat;
  time_t t2sleep;
  time_t wait_ms;

  philo->last_meal = philo->shared->params->started_at;
  t2eat = philo->shared->params->t2eat;
  t2sleep = philo->shared->params->t2sleep;
  if (t2eat + t2sleep <= philo->shared->params->t2live)
    return;
  wait_ms = t2live - (sim_time(philo->shared->params) - philo->last_meal);
  philo_say(philo, THINKING);
  ft_msleep(philo, wait_ms);
  if (!params_get_ended(p->params)) {
    philo_say(philo, DIED);
    params_set_ended(p->params);
  }
}

void *philo_routine(void *philo) {
  t_philo *p;

  p = (t_philo *)philo;
  if (!params_get_ready(p->params))
    ft_msleep(&p->params->ready, 10);
  philo_checkup(p);
  while (!params_get_ended(p->params)) {
    if (sim_time(p) - p->last_meal > p->shared->params->t2live)
      break;
    if (p->state == ALLOWED_EAT)
      philo_eat(p);
    else if (p->state == READY_SLEEP)
      philo_sleep(p);
    else if (p->state == READY_THINK) {
      philo_say(philo, THINKING);
      philo->state = READY_EAT;
    }
  }
  if (!params_get_ended(p->params)) {
    philo_say(p, DIED);
    params_set_ended(p->params);
  }
  return (NULL);
}
