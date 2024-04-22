#include "philo.h"

void params_set_ready(t_params *params) {
//  pthread_mutex_lock(&params->lock);
  params->ready = 1;
//  pthread_mutex_unlock(&params->lock);
}

int params_get_ready(t_params *params) {
  int ready;

//  pthread_mutex_lock(&params->lock);
  ready = params->ready;
//  pthread_mutex_unlock(&params->lock);
  return (ready);
}

void params_set_ended(t_params *params) {
//  pthread_mutex_lock(&params->lock);
  params->ended = 1;
//  pthread_mutex_unlock(&params->lock);
}

int params_get_ended(t_params *params) {
  int ended;

//  pthread_mutex_lock(&params->lock);
  ended = params->ended;
//  pthread_mutex_unlock(&params->lock);
  return (ended);
}