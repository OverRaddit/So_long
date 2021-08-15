CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
B_SERVER = b_server
B_CLIENT = b_client
LIBFT = include/libft
LIBFT_LIB = libft.a

LIBS = -Linclude/libft -lft

S_FILES = src_server/server.c
S_BONUS_FILES = src_server/server_bonus.c
S_OBJS = $(S_FILES:.c=.o)
S_BONUS_OBJS = $(S_BONUS_FILES:.c=.o)
C_FILES = src_client/client.c
C_BONUS_FILES = src_client/client_bonus.c
C_OBJS = $(C_FILES:.c=.o)
C_BONUS_OBJS = $(C_BONUS_FILES:.c=.o)

all : $(LIBFT_LIB) $(SERVER) $(CLIENT)

$(LIBFT_LIB) :
	make all -C $(LIBFT)

$(SERVER) : $(S_OBJS)
	gcc ${CFLAGS} -o ${SERVER} ${S_OBJS} ${LIBS}

$(CLIENT) : $(C_OBJS)
	gcc ${CFLAGS} -o ${CLIENT} ${C_OBJS} ${LIBS}

$(B_SERVER) : $(S_BONUS_OBJS)
	gcc ${CFLAGS} -o ${B_SERVER} ${S_BONUS_OBJS} ${LIBS}

$(B_CLIENT) : $(C_BONUS_OBJS)
	gcc ${CFLAGS} -o ${B_CLIENT} ${C_BONUS_OBJS} ${LIBS}

clean :
	rm -f $(S_OBJS)
	rm -f $(C_OBJS)
	rm -f $(S_BONUS_OBJS)
	rm -f $(C_BONUS_OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm ${SERVER}
	rm ${CLIENT}
	rm -f $(B_SERVER)
	rm -f $(B_CLIENT)
	make fclean -C $(LIBFT)

re : fclean all

bonus : $(LIBFT_LIB) $(B_SERVER) $(B_CLIENT)

.PHONY : all clean fclean re bonus
