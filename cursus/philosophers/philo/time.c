/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:59:26 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/04 19:03:31 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// now_ms return the current time in milliseconds
time_t now_ms(void) {
  struct timeval tv;

  gettimeofday(&tv, NULL);
  return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t sim_time(t_philo *p) {
  return (now_ms() - p->shared->params->started_at);
}

// ft_msleep sleeps for a given time in milliseconds or until ended is set to 1
void ft_msleep(t_philo *p, time_t time) {
  time_t start;

  start = now_ms();
  while (now_ms() - start < time && !params_get_ended(p->shared->params))
    usleep(150);
}
