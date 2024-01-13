#include "philo.h"

char *ft_str_status(t_status status) {
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

int ft_is_dead(t_global *g, t_philo *p) {
  time_t now;

  now = current_time_ms() - g->sim.start_time;
  return (p->status == DEAD || now >= p->t_last_meal + g->t2live);
}

int ft_positive_integer(const char *s) {
  if (s == NULL)
    return (0);
  while (*s) {
    if (*s < '0' || *s > '9')
      return (0);
    s++;
  }
  return (1);
}

int ft_atoi(const char *s) {
  int n;

  if (s == NULL)
    return (0);
  n = 0;
  while (*s) {
    n = n * 10 + (*s - '0');
    s++;
  }
  return (n);
}
