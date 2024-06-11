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


static t_philo *init_philos(t_shared *shared, t_philo *philos) {
  int i;

  i = -1;
  while (++i < shared->philos) {
    philos[i].id = i;
    philos[i].shared = shared;
    if ((i & 0x1) == 0)
      philos[i].state = READY_EAT;
    else
      philos[i].state = READY_THINK;
    philos[i].last_meal = 0;
    philos[i].dead_at = shared->t2live;
  }
  philos[shared->philos - 1].state = READY_THINK;
  i = -1;
  while (++i < shared->philos) {
    if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]) !=
        0)
        {
          printf("philo: failed to create thread\n");
          return (NULL);
        }
  }
  return (philos);
}

static void schedule(t_shared *shared, t_philo *philos) {
  int i;

  i = -1;
  while (++i < shared->philos) {
    while (!philos[i].ready);
  }
  shared->ready = 1;
  shared->started_at = now_ms();
}

static void wait(t_shared *shared, t_philo *philos) {
  int i;
  int meals_eaten;

  if (shared->meals > 0) {
    while (!shared->stopped) {
      i = -1;
      meals_eaten = 1;
      while (++i < shared->philos) {
        if (philos[i].meals < shared->meals) {
          meals_eaten = 0;
          break;
        }
      }
      if (meals_eaten)
        shared->stopped = 1;
    }
  }
  i = -1;
  while (++i < shared->philos)
    pthread_join(philos[i].thread, NULL);
}

void sim_run(t_shared *shared) {
  t_philo *philos;

  philos = ft_malloc(sizeof(t_philo) * shared->philos);
  if (philos == NULL)
    return ;
  init_philos(shared, philos);
  schedule(shared, philos);
  wait(shared, philos);
  free(philos);
}
