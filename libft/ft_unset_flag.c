#include "ft_libft.h"

inline void	ft_unset_flag(t_flag *flag, t_flag flag_to_unset)
{
	*flag &= ~flag_to_unset;
}
