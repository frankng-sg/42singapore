#include "philo.h"
#include <assert.h>

void test_ft_msleep_01(void) {
  time_t start;
  time_t end;
  int ended;

  printf("Testing ft_msleep(1) with ended = 0\n");
  ended = 0;
  start = now_ms();
  ft_msleep(&ended, 1);
  end = now_ms();
  assert(end - start == 1);
  printf("... OK\n");
}

void test_ft_msleep_02(void) {
  time_t start;
  time_t end;
  int ended;

  printf("Testing ft_msleep(10) with ended = 1\n");
  ended = 1;
  start = now_ms();
  ft_msleep(&ended, 1);
  end = now_ms();
  assert(end - start == 0);
  printf("... OK\n");
}