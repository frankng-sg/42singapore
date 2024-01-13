/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:38:16 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/04 20:28:26 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int generate_philo(t_global *g) {
  int i;

  i = -1;
  while (++i < g->n_philos) {
    if (pthread_create(&g->philos[i].thread, NULL, &philo_routine,
                       &g->philos[i]) != 0)
      return (with_error(ERR_INIT_THREAD));
  }
  return (0);
}

static int start_simulation(t_global *g) {
  int i;
  time_t now;

  now = current_time_ms();
  g->sim.start_time = now;
  g->sim.completed = 0;
  i = -1;
  while (++i < g->n_philos) {
    g->philos[i].id = i + 1;
    g->philos[i].t_last_meal = 0;
    g->philos[i].n_meals = g->n_meals;
    if (i % 2 == 0)
      g->philos[i].status = READY_TO_EAT;
    else
      g->philos[i].status = READY_TO_THINK;
    g->philos[i].g = (void *)g;
  }
  g->philos[g->n_philos - 1].status = READY_TO_THINK;
  return (generate_philo(g));
}

int run_simulation(t_global *g) {
  int i;

  if (start_simulation(g) != 0)
    return (1);
  i = -1;
  while (++i < g->n_philos)
    pthread_join(g->philos[i].thread, NULL);
  return (0);
}
