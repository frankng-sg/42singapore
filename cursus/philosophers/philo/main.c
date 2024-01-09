/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:47:11 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/04 20:37:09 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	valid_input(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (1);
}

static void	show_menu(void)
{
	printf("Usage: ./philo ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

static void	initialize(t_global *g, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	g->n_philos = 3;
	g->n_meals = 3;
	g->t2live = 600;
	g->t2eat = 100;
	g->t2sleep = 100;
}

int	main(int argc, char **argv)
{
	t_global	g;

	if (!valid_input(argc, argv))
		return (show_menu(), 0);
	initialize(&g, argc, argv);
	run_simulation(&g);
	return (0);
}
