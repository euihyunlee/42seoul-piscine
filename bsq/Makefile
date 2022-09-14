CC = gcc
CFLAGS = -Wall -Wextra -Werror

sources = main.c surveyor.c cartographer.c wayfinder.c square.c
objects = $(sources:.c=.o)
NAME = bsq

.PHONY : all
all : $(NAME)

$(NAME) : $(objects)
	$(CC) $(CFLAGS) -o $@ $^

$(objects) : katsuou.h

.PHONY : re
re: fclean all

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : clean
clean :
	rm -f $(objects) tmpfile
