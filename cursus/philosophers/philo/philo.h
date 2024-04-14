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

#define EATING "is eating"
#define SLEEPING "is sleeping"
#define THINKING "is thinking"
#define DIED "died"
#define FORK "has taken a fork"
#define MAX_PHILO 200

enum e_state {
  ALLOWED_EAT,
  READY_EAT,
  READY_SLEEP,
  READY_THINK,
} t_state;

typedef struct s_fork {
  pthread_mutex_t lock;
  int total;
  int avail[MAX_PHILO];
} t_fork;

typedef struct s_params {
  int ready;
  int ended;
  int meals;
  int philos;
  int t2live;
  int t2eat;
  int t2sleep;
  time_t started_at;
  pthread_mutex_t lock;
} t_params;

typedef struct s_shared {
  t_params params;
  t_fork forks;
  pthread_mutex_t print_lock;
} t_shared;

typedef struct s_philo {
  int id;
  int meals;
  time_t last_meal;
  t_shared *shared;
  t_state state;
  pthread_mutex_t lock;
  pthread_t thread;
} t_philo;

typedef struct s_scheduler {
  t_params *params;
  pthread_t thread;
} t_scheduler;

// fork.c
int fork_avail(t_fork *fork, int philo_id);
int fork_take(t_fork *fork, int philo_id);
int fork_drop(t_fork *fork, int philo_id);

// params.c
void params_set_ready(t_params *params);
void params_get_ready(t_params *params);
void params_set_ended(t_params *params);
void params_get_ended(t_params *params);

// time.c
time_t now_ms(void);
time_t sim_time(t_philo *p);
void ft_msleep(t_philo *p, time_t time);

// time_test.c
void test_ft_msleep_01(void);
void test_ft_msleep_02(void);

// util.c
void *ft_malloc(size_t size);
int ft_isnumeric(const char *s);
int ft_atoi(const char *s);
void *ft_memset(void *s, int c, size_t n);
int ft_putstr(char *str);

// util_test.c
void test_ft_isnumeric(void);
void test_ft_atoi(void);

// simulation.c
void sim_run(t_params *params);

#endif
