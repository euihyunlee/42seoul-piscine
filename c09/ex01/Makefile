CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(includes_dir)

includes_dir = includes
srcs_dir = srcs
sources = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
objects = $(addprefix $(srcs_dir)/, $(sources:.c=.o))

vpath %.h $(includes_dir)
vpath %.c $(srcs_dir)

.PHONY : all
all : libft.a

libft.a : $(objects)
	ar -rv libft.a $(objects)

$(objects) : ft.h

.PHONY : re
re: fclean all

.PHONY : fclean
fclean : | clean
	rm libft.a

.PHONY : clean
clean :
	rm $(objects)
