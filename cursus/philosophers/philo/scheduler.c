#include "philo.h"

static int allow_eating(int count, t_shared *g, t_philo *philo) {
  int i;
  int found;

  i = -1;
  found = 0;
  while (++i < g->params.philos) {
    if (philo[i].meals <= count && philo[i].state == READY_EAT
        && fork_avail(&g->forks, philo[i].id)) {
        fork_take(&g->forks, philo[i].id);
        philo[i].state = ALLOWED_EAT;
        found = 1;
    }
  }
  return (found);
}

void schedule(t_shared *g, t_philo *philos) {
  int meals;
  int count;

  meals = g->params.meals;
  count = 0;
  while (meals == 0 || count < meals) {
    if (params_get_ended(&g->params))
      break;
    if (!allow_eating(count, g, philos))
      count++;
    allow_eating(count+1, g, philos);
  }
}