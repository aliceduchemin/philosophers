SRCS		= srcs/main.c \
			srcs/parsing.c \
			srcs/creator.c \
			srcs/launch.c \
			srcs/time.c \
			srcs/party.c \
			srcs/destructor.c \
			srcs/utils.c


OBJS		= $(SRCS:.c=.o)

NAME		= philo_two

CC			= clang -pthread

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I ./includes

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o ${NAME} ${OBJS} ${CFLAGS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
