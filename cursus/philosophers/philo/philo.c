#include "philo.h"

static void philo_say(t_philo *philo, char *action) {
  pthread_mutex_lock(&philo->shared->print_lock);
  printf("%ld %d %s\n", sim_time(philo), philo->id + 1, action);
  pthread_mutex_unlock(&philo->shared->print_lock);
}

static void eating(t_philo *philo) {
    philo_say(philo, MSG_EAT);
    philo->meals++;
    philo->last_meal = sim_time(philo);
    philo->dead_at = philo->last_meal + philo->shared->t2live;
    ft_msleep(philo, philo->shared->t2eat);
}

static void philo_eat(t_philo *philo) {
  int right;
  int left;

  left = philo->id;
  right = 0;
  if (left + 1 < philo->shared->philos)
    right = left + 1;
  if (left != right) {
    pthread_mutex_lock(&philo->shared->fork_lock[left]);
    if (sim_time(philo) > philo->dead_at)
      return;
    philo_say(philo, MSG_FORK);
    pthread_mutex_lock(&philo->shared->fork_lock[right]);
    if (sim_time(philo) > philo->dead_at)
      return;
    philo_say(philo, MSG_FORK);
    eating(philo);
    pthread_mutex_unlock(&philo->shared->fork_lock[left]);
    pthread_mutex_unlock(&philo->shared->fork_lock[right]);
    philo->state = READY_SLEEP;
  } else {
    philo->state = DYING;
  }
}

static void philo_sleep(t_philo *philo) {
  philo_say(philo, MSG_SLEEP);
  ft_msleep(philo, philo->shared->t2sleep);
  philo->state = READY_THINK;
}



void *philo_routine(void *philo) {
  t_philo *p;

  p = (t_philo *)philo;
  p->ready = 1;
  while (!p->shared->ready);
  while (!p->shared->stopped) {
    if (sim_time(p) > p->dead_at)
      break;
    if (p->state == READY_EAT)
      philo_eat(p);
    else if (p->state == READY_SLEEP)
      philo_sleep(p);
    else if (p->state == READY_THINK)
    {
      philo_say(p, MSG_THINK);
      ft_msleep(p, p->think_time);
      p->think_time = 0;
      p->state = READY_EAT;
    }
  }
  if (!p->shared->stopped) {
    p->shared->stopped = 1;
    philo_say(p, MSG_DIE);
  }
  return (NULL);
}
