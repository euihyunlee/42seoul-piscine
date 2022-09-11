CC=gcc
AR=ar
RM=rm -f
CFLAGS= -Wall -Wextra -Werror
NAME=rush-02
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean all
