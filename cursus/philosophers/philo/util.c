#include "philo.h"

char	*ft_str_status(t_status status)
{
	if (status == EATING)
		return ("is eating");
	else if (status == SLEEPING)
		return ("is sleeping");
	else if (status == THINKING)
		return ("is thinking");
	else if (status == DEAD)
		return ("died");
	else if (status == GOT_LEFT_FORK || status == GOT_RIGHT_FORK)
		return ("has taken a fork");
	else
		return ("");
}

int	ft_is_dead(t_global *g, t_philo *p)
{
	time_t	now;

	now = current_time_ms() - g->sim.start_time;
	return (p->status == DEAD || now + g->t2eat > p->t_end_meal + g->t2live);
}
