/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:58:57 by rynitta           #+#    #+#             */
/*   Updated: 2026/02/07 10:49:01 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include "auto_flush_buffered_write.h"

typedef enum e_status
{
	ERROR = -1,
	SUCCESS = 0,
}	t_status;

typedef int	t_flag;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *buf, int ch, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *buf1, const void *buf2, size_t n);
void				*ft_memmove(void *buf1, const void *buf2, size_t n);
void				*ft_memchr(const void *buf, int ch, size_t n);
void				*ft_memrchr(const void *p, int c, size_t size);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, \
	size_t len);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				*ft_memmove(void *buf1, const void *buf2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *str, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putnbr(long long int n);
int					ft_putnbr_base(int n, char *base);
int					ft_put_unsigned_nbr(unsigned long long int n);
int					ft_put_unsigned_nbr_base(unsigned long long int n, \
	char *base);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));

long long int		ft_abs(long long int n);
int					ft_count_digits(long long int n);
int					ft_count_hex_digits(long long int n);
int					ft_count_unsigned_digits(unsigned long long int n);
int					ft_count_unsigned_hex_digits(unsigned long long int n);
int					ft_findc(char *s, char c);
bool				ft_is_flag_set(t_flag to_check, t_flag flag);
void				ft_unset_flag(t_flag *flag, t_flag flag_to_unset);

#endif
