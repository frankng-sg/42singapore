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

  philos = ft_malloc(sizeof(t_philo) * params->n_philos);
  if (philos == NULL)
    return (NULL);
  i = -1;
  while (++i < params->n_philos) {
    philos[i].id = i;
    philos[i].shared = shared;
    philos[i].state = READY_EAT;
  }
  return (philos);
}

static t_scheduler *init_scheduler(t_params *params) {
  t_scheduler *scheduler;

  scheduler = ft_malloc(sizeof(t_scheduler));
  if (scheduler == NULL)
    return (NULL);
  scheduler->params = params;
  return (scheduler);
}

static void run_scheduler(t_scheduler *scheduler) {
  if (pthread_create(&scheduler->thread, NULL, &scheduler_routine, scheduler) != 0)
    return ((void)printf("philo: failed to create scheduler thread\n"));
}

void sim_run(t_shared *shared) {
  t_philo *philos;
  t_scheduler *scheduler;

  philos = init_philos(shared);
  scheduler = init_scheduler(shared);
  if (philos == NULL || scheduler == NULL)
    return;
  run_philos(shared->params->philos, philos);
  run_scheduler(scheduler);
  params->started_at = now_ms();
  params_set_ready(shared->params);
  while (++i < params->philos)
    pthread_join(philos[i].thread, NULL);
  pthread_join(scheduler.thread, NULL);
  free(philos);
  free(scheduler);
}
