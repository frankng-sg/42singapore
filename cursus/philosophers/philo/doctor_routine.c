#include "philo.h"

void *doctor_routine(void *arg) {
  t_global *g;
  int i;

  g = (t_global *)arg;
  while (1) {
    i = -1;
    while (++i < g->n_philos) {
      if (ft_is_dead(g, &g->philos[i])) {
        g->philos[i].status = DEAD;
        ft_write_status(current_time_ms() - g->sim.start_time, g->philos[i].id,
                        ft_str_status(DEAD));
        g->sim.completed = 1;
        return (NULL);
      }
    }
    usleep(1000);
  }
}