#include "philo.h"

void	ft_get_fork(t_global *g, int id)
{
	if (id <= 0)
		id = g->n_philos;
	else if (id > g->n_philos)
		id = 1;
	pthread_mutex_lock(&g->forks[id]);
}

void	ft_return_fork(t_global *g, int id)
{
	if (id <= 0)
		id = g->n_philos;
	else if (id > g->n_philos)
		id = 1;
	pthread_mutex_unlock(&g->forks[id]);
}
