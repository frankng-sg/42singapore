/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:45:44 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/12 21:38:28 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void philo_eat(t_global *g, t_philo *p) {
  if (p->status == READY_TO_EAT)
    (ft_get_fork(g, p->id), p->status = GOT_LEFT_FORK);
  else if (p->status == GOT_LEFT_FORK && g->n_philos > 1)
    (ft_get_fork(g, p->id + 1), p->status = GOT_RIGHT_FORK);
  else if (p->status == GOT_RIGHT_FORK) {
    p->t_last_meal = current_time_ms() - g->sim.start_time;
    p->status = EATING;
  } else if (p->status == EATING && current_time_ms() - g->sim.start_time >=
                                        p->t_last_meal + g->t2eat) {
    (ft_return_fork(g, p->id), ft_return_fork(g, p->id + 1));
    p->status = READY_TO_SLEEP;
    p->n_meals--;
    return;
  } else
    return;
  printf("%ld %d %s\n", current_time_ms() - g->sim.start_time, p->id,
         ft_str_status(p->status));
}

static void philo_sleep(t_global *g, t_philo *p) {
  time_t now;

  now = current_time_ms() - g->sim.start_time;
  if (p->status == READY_TO_SLEEP) {
    printf("%ld %d %s\n", now, p->id, ft_str_status(SLEEPING));
    p->t_end_sleep = now + g->t2sleep;
    p->status = SLEEPING;
  } else if (p->status == SLEEPING && now >= p->t_end_sleep) {
    p->status = READY_TO_THINK;
  }
}

static void philo_think(t_global *g, t_philo *p) {
  time_t now;
  time_t t_think;

  now = current_time_ms() - g->sim.start_time;
  if (p->status == READY_TO_THINK) {
    printf("%ld %d %s\n", now, p->id, ft_str_status(THINKING));
    p->status = THINKING;
    t_think = (g->t2live - (now - p->t_last_meal) - g->t2eat) / 2;
    if (t_think < 0)
      t_think = 1;
    p->t_end_think = now + t_think;
  } else if (p->status == THINKING && now >= p->t_end_think) {
    p->status = READY_TO_EAT;
  }
}

static void philo_die(t_global *g, t_philo *p) {
  int i;
  time_t now;

  i = -1;
  while (++i < g->n_philos)
    pthread_mutex_unlock(&g->forks[i]);
  p->status = DEAD;
  g->sim.completed = 1;
  now = current_time_ms() - g->sim.start_time;
  printf("%ld %d %s\n", now, p->id, ft_str_status(DEAD));
}

void *philo_routine(void *arg) {
  t_philo *p;
  t_global *g;

  p = (t_philo *)arg;
  g = (t_global *)p->g;
  if (g == NULL || g->t2live <= 0)
    return (NULL);
  while (!g->sim.completed && p->status != DEAD) {
    if (g->n_meals >= 0 && p->n_meals < 0)
      break;
    if (ft_is_dead(g, p))
      philo_die(g, p);
    else if (p->status == READY_TO_EAT || p->status == EATING ||
             p->status == GOT_LEFT_FORK || p->status == GOT_RIGHT_FORK)
      philo_eat(g, p);
    else if (p->status == READY_TO_SLEEP || p->status == SLEEPING)
      philo_sleep(g, p);
    else if (p->status == READY_TO_THINK || p->status == THINKING)
      philo_think(g, p);
  }
  (ft_return_fork(g, p->id - 1), ft_return_fork(g, p->id));
  return (NULL);
}
