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
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

/******************************************************************************
* CONFIGURATION                                                               *
******************************************************************************/

# define MAX_PHILOS 200
# define MIN_ACT_TIME 60

/******************************************************************************
* DATA STRUCTURE                                                              *
******************************************************************************/

typedef struct s_simulation
{
	time_t			start_time;
	int				completed;
}					t_simulation;

typedef enum e_status
{
	READY_TO_THINK,
	THINKING,
	READY_TO_EAT,
	EATING,
	READY_TO_SLEEP,
	SLEEPING,
	GOT_LEFT_FORK,
	GOT_RIGHT_FORK,
	DEAD
}					t_status;

typedef struct s_philo
{
	int				id;
	int				n_meals;
	time_t			t_end_meal;
	time_t			t_end_sleep;
	time_t			t_end_think;
	pthread_t		thread;
	t_status		status;
	void			*g;
}					t_philo;

typedef struct s_global
{
	int				n_philos;
	int				n_meals;
	int				t2live;
	int				t2eat;
	int				t2sleep;
	t_simulation	sim;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];
}					t_global;

/******************************************************************************
* ERRORS                                                                      *
******************************************************************************/

# define ERR_INIT_THREAD "philo: error: failed to initialize thread"

/******************************************************************************
* APIs                                                                        *
******************************************************************************/

// simulation.c
int					run_simulation(t_global *g);

// time.c
time_t				current_time_ms(void);

// error.c
int					with_error(char *msg);

// routine.c
void				*philo_routine(void *arg);
void				*health_monitor(void *arg);

// util.c
char				*ft_str_status(t_status status);
int					ft_is_dead(t_global *g, t_philo *p);

// fork.c
void				ft_get_fork(t_global *g, int id);
void				ft_return_fork(t_global *g, int id);

#endif
