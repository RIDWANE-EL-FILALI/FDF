NAME = fdf.a
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -lmlx -framework appkit -framework openGl
RM = rm -f
SRC = draw_map.c ft_atoi.c ft_error.c ft_split.c get_next_line.c get_next_line_utils.c key_hook.c main.c menu.c read_map.c scale.c utils.c
ASCII = 	███████╗██████╗ ███████╗      ██╗    ██╗██╗██████╗ ███████╗███████╗██████╗  █████╗ ███╗   ███╗███████╗\n\
			██╔════╝██╔══██╗██╔════╝      ██║    ██║██║██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗████╗ ████║██╔════╝\n\
			█████╗  ██║  ██║█████╗  █████╗██║ █╗ ██║██║██████╔╝█████╗  █████╗  ██████╔╝███████║██╔████╔██║█████╗  \n\
			██╔══╝  ██║  ██║██╔══╝  ╚════╝██║███╗██║██║██╔══██╗██╔══╝  ██╔══╝  ██╔══██╗██╔══██║██║╚██╔╝██║██╔══╝  \n\
			██║     ██████╔╝██║           ╚███╔███╔╝██║██║  ██║███████╗██║     ██║  ██║██║  ██║██║ ╚═╝ ██║███████╗\n\
			╚═╝     ╚═════╝ ╚═╝            ╚══╝╚══╝ ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n

BGreen=\033[1;32m

OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ) fdf.h
	@echo "$(BGreen) ${ASCII}"
	@ar rc $(NAME) $(OBJ)
	@${CC} ${CFLAGS} ${FRAMEWORK} main.c ${NAME} -o fdf
clean :
	@echo "$(BGreen) All obj file deleted"
	@${RM} ${OBJ} ${NAME}
fclean : clean
	@echo "$(BGreen) deleted all obj file and the executable file fdf"
	@${RM} $(NAME) fdf
re : fclean all