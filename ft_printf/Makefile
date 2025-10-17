SRCS    = ft_printf.c auto_flush_buffered_write/auto_flush_buffered_write.c \
	case_conversion/case_c.c  case_conversion/case_d.c  case_conversion/case_p.c  case_conversion/case_s.c  case_conversion/case_u.c case_conversion/case_xX.c \
	case_conversion/load_conversion.c case_conversion/utils.c is_conversion.c

SRCS_BONUS = ft_printf.c is_conversion.c 

OBJS    = ${SRCS:.c=.o}
OBJS_BONUS    = ${SRCS_BONUS:.c=.o}
INCS    = includes
NAME    = libftprintf.a
NAME_BONUS = libftprintf.a

LIBC    = ar rcs
LIBR    = ranlib
CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror 

LIB_DIR = libft
LIB_NAME = libft
LIB = $(LIB_DIR)/$(LIB_NAME).a

.c.o:
	${CC} ${CFLAGS} -c $< -o $@
${NAME}: ${OBJS} ${LIB}
	${LIBC} ${NAME} ${OBJS}
#	${LIBR} ${NAME}
all: ${NAME}
bonus: ${OBJS} ${OBJS_BONUS} ${LIB}
	${LIBC} ${NAME} ${OBJS} ${OBJS_BONUS}
	${LIBR} ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_BONUS}
	${MAKE} -C ${LIB_DIR} clean
fclean: clean
	${RM} ${NAME}
	${RM} ${LIB}
re: fclean all
${OBJS}: ${LIB}
${LIB}:
	${MAKE} -C ${LIB_DIR}
	cp ${LIB} ${NAME}
.PHONY: all bonus clean fclean re .c.o ${LIB}