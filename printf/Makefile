SRCS = ft_printf.c ft_put_char.c ft_put_str.c ft_put_adr.c ft_put_hexa.c \
		ft_put_Nbr.c ft_put_unbr.c

OBJS = ${SRCS:.c=.o}

LIBC = ar rcs

NAME = libftprintf.a

RM = rm -rf

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $<

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
