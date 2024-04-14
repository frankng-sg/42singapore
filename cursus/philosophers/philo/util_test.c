#include "philo.h"
#include <assert.h>

void test_ft_isnumeric(void) {
  printf("Test ft_isnumeric\n");
  assert(ft_isnumeric("123") == 1);
  assert(ft_isnumeric("123a") == 0);
  assert(ft_isnumeric("a123") == 0);
  assert(ft_isnumeric("123\n") == 0);
  assert(ft_isnumeric("123 ") == 0);
  assert(ft_isnumeric(" 123") == 0);
  assert(ft_isnumeric("123") == 1);
  assert(ft_isnumeric("") == 0);
  assert(ft_isnumeric(NULL) == 0);
  printf("... OK\n");
}

void test_ft_atoi(void) {
  printf("Test ft_atoi\n");
  assert(ft_atoi("123") == 123);
  assert(ft_atoi("123a") == 123);
  assert(ft_atoi("a123") == 0);
  assert(ft_atoi("123\n") == 123);
  assert(ft_atoi("123 ") == 123);
  assert(ft_atoi("123") == 123);
  assert(ft_atoi("") == 0);
  assert(ft_atoi(NULL) == 0);
  printf("... OK\n");
}