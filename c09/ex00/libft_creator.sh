#!/bin/sh
gcc -Wall -Wextra -Werror -c *.c
ar -rv libft.a *.o
