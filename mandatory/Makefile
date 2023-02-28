NAME = fdf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -lmlx -framework appkit -framework openGl
RM = rm -f
SRC = draw_map.c ft_atoi.c ft_error.c ft_split.c get_next_line.c get_next_line_utils.c key_hook.c main.c menu.c read_map.c scale.c 

OBJ = ${MSRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ) fdf.h
	@ar rc $(NAME) $(OBJ)
	@${CC} ${CFLAGS} ${FRAMEWORK} main.c ${NAME} -o fdf
clean :
	@${RM} ${OBJ}
fclean : clean
	@${RM} $(NAME) fdf
re : fclean all