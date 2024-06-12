/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:38:16 by vietnguy          #+#    #+#             */
/*   Updated: 2024/02/03 14:19:48 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void wait_ready(t_shared *shared, t_philo *philos, time_t delay) {
  int i;

  philos[shared->philos - 1].state = READY_THINK;
  philos[shared->philos - 1].delay = delay;
  i = -1;
  while (++i < shared->philos) {
    while (!philos[i].ready)
      ;
  }
  shared->started_at = now_ms();
  shared->ready = 1;
}

static void init_philos(t_shared *shared, t_philo *philos, int start_at, time_t delay, enum e_state state) {
  int i;

  i = start_at;
  while (i < shared->philos) {
    philos[i].id = i;
    philos[i].shared = shared;
    philos[i].last_meal = 0;
    philos[i].dead_at = shared->t2live;
    philos[i].delay = delay;
    philos[i].state = state;
    if (philos[i].id + 1 < philos[i].shared->philos)
      philos[i].right_fork = &philos[i + 1].left_fork;
    else
      philos[i].right_fork = &philos[0].left_fork;
    i += 2;
  }
  i = start_at;
  while (i < shared->philos) {
    pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]);
    i += 2;
  }
}

static void wait_meals(t_shared *shared, t_philo *philos) {
  int i;

  if (shared->meals <= 0)
    return;
  while (!shared->stopped) {
    i = -1;
    while (++i < shared->philos) {
      if (philos[i].meals >= shared->meals) {
        shared->stopped = 1;
        return;
      }
    }
  }
}

static void wait_philos(t_shared *shared, t_philo *philos) {
  int i;

  wait_meals(shared, philos);
  i = -1;
  while (++i < shared->philos)
    pthread_join(philos[i].thread, NULL);
}

void sim_run(t_shared *shared) {
  t_philo *philos;
  time_t delay;

  if (shared->philos == 1) {
    printf("0 1 has taken a fork\n");
    usleep(shared->t2live * 1000);
    printf("%d 1 died\n", shared->t2live);
    return;
  }
  philos = ft_malloc(sizeof(t_philo) * shared->philos);
  if (philos == NULL)
    return;
  delay = 5;
  init_philos(shared, philos, 0, 0, READY_EAT);
  init_philos(shared, philos, 1, delay, READY_THINK);
  wait_ready(shared, philos, delay);
  wait_philos(shared, philos);
  free(philos);
}
