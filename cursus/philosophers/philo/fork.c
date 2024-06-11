#include "philo.h"

int	forks_avail(t_philo *philo, int left, int right)
{
	int	left_avail;
	int	right_avail;

	if (left == right)
		return (0);
	left_avail = philo->shared->fork_used[left] == 0;
	right_avail = philo->shared->fork_used[right] == 0;
	return (left_avail & right_avail);
}

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
