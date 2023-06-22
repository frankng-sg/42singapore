#!/bin/bash

cc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
