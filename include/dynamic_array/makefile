CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libda.a

SRCS = dynamic_array.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : $(OBJS)
	rm -f $(OBJS)

fclean : $(OBJS) $(OBJS) $(NAME)
	rm -f $^

re : fclean
	make all
