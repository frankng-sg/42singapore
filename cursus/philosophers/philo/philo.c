#include "philo.h"

static void philo_say(t_philo *philo, char *action) {
  time_t now;
  int id;

  now = sim_time(philo);
  id = philo->id + 1;
  pthread_mutex_lock(philo->printer);
  printf("%ld %d %s\n", now, id, action);
  pthread_mutex_unlock(philo->printer);
}

static void eating(t_philo *p) {
  philo_say(p, MSG_EAT);
  p->meals++;
  p->last_meal = sim_time(p);
  p->dead_at = p->last_meal + p->shared->t2live;
  ft_msleep(p, p->shared->t2eat);
}

static void philo_eat(t_philo *p) {
  if (p->state != READY_FORKS) {
    pthread_mutex_lock(&p->left_fork);
    philo_say(p, MSG_FORK);
    pthread_mutex_lock(p->right_fork);
    philo_say(p, MSG_FORK);
    p->state = READY_FORKS;
  }
  if (p->shared->t2eat >= p->shared->t2live)
    return;
  eating(p);
  pthread_mutex_unlock(&p->left_fork);
  pthread_mutex_unlock(p->right_fork);
  p->state = READY_SLEEP;
}

static void routine_loop(t_philo *p) {
  while (!p->shared->stopped) {
    if (sim_time(p) > p->dead_at)
      break;
    if (p->state == READY_EAT)
      philo_eat(p);
    else if (p->state == READY_SLEEP) {
      philo_say(p, MSG_SLEEP);
      ft_msleep(p, p->shared->t2sleep);
      p->state = READY_THINK;
    } else if (p->state == READY_THINK) {
      philo_say(p, MSG_THINK);
      ft_msleep(p, p->delay);
      p->delay = 0;
      p->state = READY_EAT;
    }
  }
}

void *philo_routine(void *philo) {
  t_philo *p;

  p = (t_philo *)philo;
  p->ready = 1;
  while (!p->shared->ready)
    ;
  routine_loop(p);
  if (!p->shared->stopped) {
    p->shared->stopped = 1;
    philo_say(p, MSG_DIE);
  }
  return (NULL);
}
