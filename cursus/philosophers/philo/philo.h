/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:22:06 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/04 20:27:19 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MSG_EAT "is eating"
#define MSG_SLEEP "is sleeping"
#define MSG_THINK "is thinking"
#define MSG_DIE "died"
#define MSG_FORK "has taken a fork"
#define MAX_PHILO 200

enum e_state {
  READY_EAT,
  READY_SLEEP,
  READY_THINK,
  DYING,
};

typedef struct s_shared {
  int ready;
  int stopped;
  int meals;
  int philos;
  int t2live;
  int t2eat;
  int t2sleep;
  time_t started_at;
  pthread_mutex_t fork_lock[MAX_PHILO];
  pthread_mutex_t print_lock;
} t_shared;

typedef struct s_philo {
  int id;
  int meals;
  int ready;
  time_t think_time;
  time_t last_meal;
  time_t dead_at;
  t_shared *shared;
  enum e_state state;
  pthread_t thread;
} t_philo;

// simulation.c
void sim_run(t_shared *shared);

// philo.c
void *philo_routine(void *philo);

// time.c
time_t sim_time(t_philo *p);
time_t now_ms(void);
void ft_msleep(t_philo *p, time_t time);

// util.c
int ft_putstr(char *str);
void *ft_malloc(size_t size);
void *ft_memset(void *s, int c, size_t n);
int ft_atoi(const char *s);
int ft_isnumeric(const char *s);

#endif
