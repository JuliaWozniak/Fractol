NAME = fractol

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_D = ./src/
SRC = 	main.c \
		mandelbrot.c \
		initialization.c \
		zoom.c \
		colors.c \
		image.c \
		events.c \
		error.c \
		julia.c \
		ship.c
SRCS = $(addprefix $(SRC_D),$(SRC))

OBJS = $(SRCS:.c=.o)

MFLAGS = -lmlx -framework OpenGL -framework AppKit

LIB_D = ./libft/
FT_LIB = $(addprefix $(LIB_D),libft.a)
LIB_INC = -I ./libft
LIB_L = -L $(LIB_D) -l ft

MLX_D = ./minilibx_macos/
MLX_LIB = $(addprefix $(MLX_D),mlx.a)
MLX_INC = -I ./minilibx_macos
MLX_L = -L ./minilibx_macos $(MFLAGS)

all: $(FT_LIB) $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(LIB_INC) -o $@ -c $<
$(MLX_LIB):
	make -C $(MLX_D)
$(FT_LIB):
	make -C $(LIB_D) 
$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(LIB_L)  -lm -o $(NAME)
clean:
	rm $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean all
