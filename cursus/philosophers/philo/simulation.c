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

static int	start_simulation(t_global *g)
{
	int	i;

	g->sim.start_time = current_time_ms();
	g->sim.completed = 0;
	i = -1;
	while (++i < g->n_philos)
	{
		g->philos[i].last_meal = g->sim.start_time;
		g->philos[i].id = i + 1;
		g->philos[i].n_meals = 0;
		g->philos[i].g = (void *)g;
		if (pthread_create(&g->philos[i].thread, NULL, &philo_routine,
				&g->philos[i]) != 0)
			return (with_error(ERR_INIT_THREAD));
	}
	if (pthread_create(&g->doctor, NULL, &health_monitor, g) != 0)
	{
		g->sim.completed = 1;
		return (with_error(ERR_INIT_THREAD));
	}
	return (0);
}

int	run_simulation(t_global *g)
{
	int	i;

	if (start_simulation(g) != 0)
		return (1);
	i = -1;
	while (++i < g->n_philos)
		pthread_join(g->philos[i].thread, NULL);
	pthread_join(g->doctor, NULL);
	return (0);
}
