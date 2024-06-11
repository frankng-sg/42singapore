#include "philo.h"

static void	show_menu(void)
{
	printf("Usage: ./philo ");
	printf("<number_of_philosophers> ");
	printf("<time_to_die> ");
	printf("<time_to_eat> ");
	printf("<time_to_sleep> ");
	printf("[max_meals_per_philosopher]\n");
	printf("Note: [max_meals_per_philosopher] is optional\n");
	printf("Example 1: ./philo 5 800 200 200\n");
	printf("Example 2: ./philo 5 800 200 200 3\n");
}

static int	valid_input(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!ft_isnumeric(argv[i]))
			return (0);
	}
	return (1);
}

static void	initialize(t_shared *shared, int argc, char **argv)
{
	ft_memset(shared, 0, sizeof(t_shared));
	shared->philos = ft_atoi(argv[1]);
	shared->t2live = ft_atoi(argv[2]);
	shared->t2eat = ft_atoi(argv[3]);
	shared->t2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		shared->meals = ft_atoi(argv[5]);
	shared->ready = 0;
}

int	main(int argc, char **argv)
{
	t_shared	shared;

	if (!valid_input(argc, argv))
		return (show_menu(), 1);
	initialize(&shared, argc, argv);
	sim_run(&shared);
}
