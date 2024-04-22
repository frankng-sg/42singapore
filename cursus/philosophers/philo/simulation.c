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

static void run_philos(int n, t_philo *philos) {
  int i;

  i = -1;
  while (++i < n) {
    if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]) !=
        0)
      return ((void)printf("philo: failed to create thread\n"));
  }
}

static t_philo *init_philos(t_shared *shared) {
  t_philo *philos;
  int i;

  philos = ft_malloc(sizeof(t_philo) * shared->params.philos);
  if (philos == NULL)
    return (NULL);
  i = -1;
  while (++i < shared->params.philos) {
    philos[i].id = i;
    philos[i].shared = shared;
    philos[i].state = READY_EAT;
  }
  return (philos);
}

void sim_run(t_shared *shared) {
  t_philo *philos;
  int i;

  philos = init_philos(shared);
  if (philos == NULL)
    return;
  run_philos(shared->params.philos, philos);
  shared->params.started_at = now_ms();
  params_set_ready(&shared->params);
  schedule(shared, philos);
  i = 0;
  while (++i < shared->params.philos)
    pthread_join(philos[i].thread, NULL);
  free(philos);
}
