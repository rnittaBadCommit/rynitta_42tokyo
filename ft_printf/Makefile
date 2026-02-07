SRCS    = ft_printf.c \
	case_conversion/case_c.c  case_conversion/case_d.c  case_conversion/case_p.c  case_conversion/case_s.c  case_conversion/case_u.c case_conversion/case_xx.c \
	case_conversion/load_conversion.c case_conversion/calculate_len_numbers.c case_conversion/calculate_len_numbers_unsigned.c is_conversion.c

OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = libftprintf.a

LIBC    = ar rcs
LIBR    = ranlib
CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror 

LIB_DIR = libft
LIB_NAME = libft
LIB = $(LIB_DIR)/$(LIB_NAME).a

ifeq (${IS_BONUS}, true)
	OBJS += ${OBJS_BONUS}
endif

.c.o:
	${CC} ${CFLAGS} -c $< -o $@
${NAME}: ${OBJS} ${LIB}
	${LIBC} ${NAME} ${OBJS}
#	${LIBR} ${NAME}
all:  ${OBJS} ${LIB}
	@make -e --no-print-directory
bonus:  ${OBJS} ${LIB}
	@make -e --no-print-directory
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
.PHONY: all bonus clean fclean re .c.o