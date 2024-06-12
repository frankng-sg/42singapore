#include "philo.h"


void	take_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->shared->fork_lock[fork_id]);
	philo->shared->fork_used[fork_id] = 1;
}

void	release_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_unlock(&philo->shared->fork_lock[fork_id]);
	philo->shared->fork_used[fork_id] = 0;
}
