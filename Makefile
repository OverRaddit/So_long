CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
#CFLAGS = -Wall -g

NAME = so_long
#B_NAME = bonus_so_long

SRCS_DIR = ./src
SRCS = src/main.c src/so_long_init.c src/so_long_game.c
#SRCS_BONUS = src/bonus_so_long.c
OBJS = $(SRCS:.c=.o)
#BONUS_OBJS = $(SRCS_BONUS:.c=.o)

# 외부라이브러리 모음 =================================================
LIB_NAME = ft
LIB_DIR = ./include/libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

MLX_NAME = mlx
MLX_DIR = ./include/minilibx_mms_20210621
MLX = $(addprefix $(MLX_DIR)/, libmlx.dylib)	# MLX/DIR/libmlx.a를 생성

GNL_NAME = gnl
GNL_DIR = ./include/gnl
GNL = $(addprefix $(GNL_DIR)/, libgnl.a)

DA_NAME = da
DA_DIR = ./include/dynamic_array
DA = $(addprefix $(DA_DIR)/, libda.a)
# 외부라이브러리 모음 ===================================================

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(GNL_DIR) all
	$(MAKE) -C $(DA_DIR) all
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
			-L$(GNL_DIR) -l$(GNL_NAME) -L$(DA_DIR) -l$(DA_NAME) \
			-framework OpenGL -framework AppKit $^ -o $@
	@install_name_tool -change libmlx.dylib ./include/minilibx_mms_20210621/libmlx.dylib $(NAME)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIB_DIR) -I$(GNL_DIR) -c $< -o $@

all : $(NAME)


clean :
	rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(DA_DIR) clean

fclean :
	rm -rf $(NAME) $(OBJS)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(DA_DIR) fclean

re : fclean all

#bonus : $(LIBFT_LIB) $(B_SERVER)

.PHONY : all clean fclean re bonus
