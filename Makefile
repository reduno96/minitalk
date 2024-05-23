SRCM= ./client.c \
	./server.c \

OBJM= ${SRCM:.c=.o}

CC= cc
CFLAGS= -Wall -Wextra -Werror
CNAME= client
SNAME= server

LIBPRINT= ./printf/libftprintf.a
FLDPRINTF= ./printf

LIBFT= ./libft/libft.a
FLDLIBFT= ./libft


all: ${LIBFT} ${LIBPRINT} ${OBJM} ${CNAME} ${SNAME}

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

${CNAME}: ${OBJM} minitalk.h
	${CC} ${CFLAGS} ${LIBPRINT} ${LIBFT} client.c -o ${CNAME}

${SNAME}: ${OBJM} minitalk.h
	${CC} ${CFLAGS} ${LIBPRINT} ${LIBFT} server.c -o ${SNAME}


${LIBPRINT}:
	@make -C ${FLDPRINTF}

${LIBFT}:
	@make -C ${FLDLIBFT}

clean:
	make fclean -C ${FLDPRINTF}
	make fclean -C ${FLDLIBFT}
	rm -rf ${OBJM}

fclean: clean
	rm -rf ${CNAME} ${SNAME}

.PHONY: all clean fclean re
