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

static int	create_threads(t_global *g)
{
	int	i;

	i = -1;
	while (++i < g->n_philos)
	{
		if (pthread_create(&g->philos[i].thread, NULL, &philo_routine,
				&g->philos[i]) != 0)
			return (with_error(ERR_INIT_THREAD));
	}
	if (pthread_create(&g->doctor, NULL, &doctor_routine, g) != 0)
		return (with_error(ERR_INIT_THREAD));
	return (0);
}

static int	start_simulation(t_global *g)
{
	int	i;

	g->sim.completed = 0;
	i = -1;
	while (++i < g->n_philos)
	{
		g->philos[i].id = i + 1;
		g->philos[i].t_last_meal = 0;
		g->philos[i].n_meals = g->n_meals;
		pthread_mutex_init(&g->forks[i], NULL);
		if (i % 2 == 0)
			g->philos[i].status = READY_TO_EAT;
		else
			g->philos[i].status = READY_TO_THINK;
		g->philos[i].g = (void *)g;
	}
	g->philos[g->n_philos - 1].status = READY_TO_THINK;
	g->sim.start_time = current_time_ms();
	return (create_threads(g));
}

int	run_simulation(t_global *g)
{
	int	i;

	if (start_simulation(g) != 0)
		return (1);
	i = -1;
	while (++i < g->n_philos)
		pthread_join(g->philos[i].thread, NULL);
	return (0);
}
