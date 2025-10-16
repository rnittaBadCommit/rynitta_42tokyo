# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 05:56:07 by rynitta           #+#    #+#              #
#    Updated: 2025/10/16 05:56:37 by rynitta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    = ft_bzero.c ft_memset.c ft_memcpy.c ft_memchr.c \
					ft_memcmp.c ft_strlen.c ft_isalpha.c  ft_isdigit.c ft_isalnum.c \
					ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_striteri.c ft_memmove.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
            ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS    = ${SRCS:.c=.o}
OBJS_BONUS    = ${SRCS_BONUS:.c=.o}
INCS    = includes
NAME    = libft.a
NAME_BONUS = libft.a
LIBC    = ar rc
LIBR    = ranlib
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}
all: ${NAME}
bonus: ${OBJS} ${OBJS_BONUS}
	${LIBC} ${NAME} ${OBJS} ${OBJS_BONUS}
	${LIBR} ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_BONUS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all bonus clean fclean re .c.o
