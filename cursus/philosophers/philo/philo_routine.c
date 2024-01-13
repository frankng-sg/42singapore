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
  time_t now;

  now = current_time_ms() - g->sim.start_time;
  if (p->status == READY_TO_EAT)
    (ft_get_fork(g, p->id), p->status = GOT_LEFT_FORK);
  else if (p->status == GOT_LEFT_FORK && g->n_philos > 1) {
    ft_write_status(now, p->id, ft_str_status(GOT_LEFT_FORK));
    (ft_get_fork(g, p->id + 1), p->status = GOT_RIGHT_FORK);
  } else if (p->status == GOT_RIGHT_FORK) {
    ft_write_status(now, p->id, ft_str_status(GOT_RIGHT_FORK));
    p->t_last_meal = current_time_ms() - g->sim.start_time;
    p->status = EATING;
    p->n_meals--;
    ft_write_status(now, p->id, ft_str_status(EATING));
  } else if (p->status == EATING && now >= p->t_last_meal + g->t2eat) {
    p->status = READY_TO_SLEEP;
  }
}

static void philo_sleep(t_global *g, t_philo *p) {
  time_t now;

  now = current_time_ms() - g->sim.start_time;
  if (p->status == READY_TO_SLEEP) {
    ft_write_status(now, p->id, ft_str_status(SLEEPING));
    (ft_return_fork(g, p->id), ft_return_fork(g, p->id + 1));
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
    p->status = THINKING;
    t_think = g->t2live - (now - p->t_last_meal) - g->t2eat;
    if (t_think < 1)
      t_think = 1;
    p->t_end_think = now + t_think;
    ft_write_status(now, p->id, ft_str_status(THINKING));
  } else if (p->status == THINKING && now >= p->t_end_think) {
    p->status = READY_TO_EAT;
  }
}

void *philo_routine(void *arg) {
  t_philo *p;
  t_global *g;

  p = (t_philo *)arg;
  g = (t_global *)p->g;
  while (!g->sim.completed) {
    if (g->n_meals >= 0 && p->n_meals < 0)
      break;
    else if (p->status == READY_TO_EAT || p->status == EATING ||
             p->status == GOT_LEFT_FORK || p->status == GOT_RIGHT_FORK)
      philo_eat(g, p);
    else if (p->status == READY_TO_SLEEP || p->status == SLEEPING)
      philo_sleep(g, p);
    else if (p->status == READY_TO_THINK || p->status == THINKING)
      philo_think(g, p);
  }
  ft_return_fork(g, p->id);
  ft_return_fork(g, p->id + 1);
  return (NULL);
}
