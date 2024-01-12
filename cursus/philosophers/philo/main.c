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

static int valid_input(int argc, char **argv) {
  int i;

  if (argc != 5 && argc != 6)
    return (0);
  i = 0;
  while (++i < argc) {
    if (!ft_positive_integer(argv[i]))
      return (0);
  }
  return (1);
}

static void show_menu(void) {
  printf("Usage: ./philo ");
  printf("<number_of_philosophers> ");
  printf("<time_to_die> ");
  printf("<time_to_eat> ");
  printf("<time_to_sleep> ");
  printf("[max_meals_per_philosopher]\n");
  printf("Note: [max_meals_per_philosopher] is optional\n");
  printf("Example: ./philo 5 800 200 200\n");
}

static void initialize(t_global *g, int argc, char **argv) {
  g->n_philos = ft_atoi(argv[1]);
  g->t2live = ft_atoi(argv[2]);
  g->t2eat = ft_atoi(argv[3]);
  g->t2sleep = ft_atoi(argv[4]);
  if (argc == 6)
    g->n_meals = ft_atoi(argv[5]);
  else
    g->n_meals = -1;
}

int main(int argc, char **argv) {
  t_global g;

  if (!valid_input(argc, argv))
    return (show_menu(), 0);
  initialize(&g, argc, argv);
  run_simulation(&g);
  return (0);
}
