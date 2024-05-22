SRCM= ./client.c \
	./server.c \

OBJM= ${SRCM=.c:.o}

CC= cc
CFLAGS= -Wall -Wextra -Werror
CNAME= client
SNAME= server

LIBPRINT= ./printf/libftprintf.a
FLDPRINTF= ./printf

LIBFT= ./libft/libft.a
FLDLIBFT= ./libft
# # LIBC= ar rcs

# # all:  ${CNAME}

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # ${CNAME}: ${OBJM}
# # 	${LIBC} ${NAME} ${OBJM}

all:  ${CNAME}

${CNAME}: ${OBJM}
	${CC} ${CFLAGS} ${LIBPRINT} ${LIBFT} ${SRCM}

${LIBPRINT}:
	@make -c FLDPRINTF

${LIBFT}:
	@make -c ${FLDLIBFT}
