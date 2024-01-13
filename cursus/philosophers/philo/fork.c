#include "philo.h"

static int ft_conv_fork_id(int n, int id) {
  if (id <= 0)
    return (n - 1);
  if (id > n)
    return (0);
  return (id - 1);
}

void ft_get_fork(t_global *g, int id) {
  id = ft_conv_fork_id(g->n_philos, id);
  pthread_mutex_lock(&g->forks[id]);
}

void ft_return_fork(t_global *g, int id) {
  id = ft_conv_fork_id(g->n_philos, id);
  pthread_mutex_unlock(&g->forks[id]);
}
