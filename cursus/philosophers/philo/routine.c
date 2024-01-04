/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:45:44 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/04 20:27:55 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_global	*g;

	philo = (t_philo *)arg;
	g = (t_global *)philo->g;
	printf("philo %d\n", philo->id);
	return (NULL);
}

void	*health_monitor(void *arg)
{
	t_global	*g;

	g = (t_global *)arg;
	printf("monitor %d philos\n", g->n_philos);
	return (NULL);
}
