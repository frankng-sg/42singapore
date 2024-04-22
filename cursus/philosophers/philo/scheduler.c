#include "philo.h"

int params_get_wellfed(t_params *params) {
  int wellfed;

  pthread_mutex_lock(&params->lock);
  wellfed = params->wellfed;
  pthread_mutex_unlock(&params->lock);
  return (wellfed);
}

void params_set_wellfed(t_params *params) {
  pthread_mutex_lock(&params->lock);
  params->wellfed++;
  pthread_mutex_unlock(&params->lock);
}

void schedule(t_shared *g, t_philo *philos) {
  int i;
  int found;
  int seed;

  while (!params_get_ended(&g->params) &&
         params_get_wellfed(&g->params) <= g->params.philos) {
    i = -1;
    seed = 0;
    found = 0;
    while (++i < g->params.philos) {
      if (philos[i].dead_at <= philos[seed].dead_at &&
          philos[i].state == READY_EAT && fork_avail(&g->forks, i)) {
        seed = i;
        found = 1;
      }
    }
    if (found) {
      fork_take(&g->forks, seed);
      philos[seed].state = ALLOWED_EAT;
    } else
      usleep(50);
  }
}