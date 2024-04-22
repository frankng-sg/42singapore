#include "philo.h"

static void fork_lookup(t_fork *fork, int philo_id, int *left, int *right) {
  *left = philo_id;
  *right = philo_id + 1;
  if (*right >= fork->total)
    *right = 0;
}

// fork_avail return 1 if both left and right forks are available, 0 otherwise
int fork_avail(t_fork *fork, int philo_id) {
  int left;
  int right;
  int avail;

  pthread_mutex_lock(&fork->lock);
  fork_lookup(fork, philo_id, &left, &right);
  if (fork->taken[left] || fork->taken[right])
    avail = 0;
  else
    avail =1;
  pthread_mutex_unlock(&fork->lock);
  return (avail);
}

// fork_take takes both left and right forks
void fork_take(t_fork *fork, int philo_id) {
  int left;
  int right;

  pthread_mutex_lock(&fork->lock);
  fork_lookup(fork, philo_id, &left, &right);
  fork->taken[left] = 1;
  fork->taken[right] = 1;
  pthread_mutex_unlock(&fork->lock);
}

// fork_drop drops both left and right forks
void fork_drop(t_fork *fork, int philo_id) {
  int left;
  int right;

  pthread_mutex_lock(&fork->lock);
  fork_lookup(fork, philo_id, &left, &right);
  fork->taken[left] = 0;
  fork->taken[right] = 0;
  pthread_mutex_unlock(&fork->lock);
}