#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef enum e_status
{
	ERROR = -1,
	SUCCESS = 0,

}	t_status;

typedef int	t_flag;

int		ft_strlen(char *s);
void	ft_strcpy(char *dest, char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_memzero(void *p, size_t size);
int		ft_findc(char *s, char c);
bool	ft_is_flag_set(int to_check, int flag);
void	ft_unset_flag(t_flag *flag, t_flag flag_to_unset);
int		ft_atoi(char *s);
int		ft_count_digits(int n);
int		ft_count_hex_digits(int n);
int		ft_put_number(int n);
int		ft_putnbr_base(int n, char *base);

long long int	ft_abs(long long int n);

#endif
