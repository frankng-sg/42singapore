#include "philo.h"

static int	found_dead(t_global *g)
{
	int	i;

	i = -1;
	while (++i < g->n_philos)
	{
		if (ft_is_dead(g, &g->philos[i]))
		{
			g->philos[i].status = DEAD;
			ft_write_status(current_time_ms() - g->sim.start_time,
							g->philos[i].id,
							ft_str_status(DEAD));
			g->sim.completed = 1;
			return (1);
		}
	}
	return (0);
}

static int	all_fed(t_global *g)
{
	int	i;
	int	cnt;

	if (g->n_meals <= 0)
		return (0);
	cnt = 0;
	i = -1;
	while (++i < g->n_philos)
	{
		if (g->philos[i].n_meals <= 0)
			cnt++;
	}
	if (cnt >= g->n_philos)
		return (1);
	return (0);
}

void	*doctor_routine(void *arg)
{
	t_global	*g;

	g = (t_global *)arg;
	while (1)
	{
		if (found_dead(g) || all_fed(g))
		{
			g->sim.completed = 1;
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
