#include "push_swap.h"

static inline t_status _check_argc(int argc)
{
	if (argc == 1)
		return (INVALID);
	return (VALID);
}

static inline bool ___is_valid_integer(char *s)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == false)
			return (false);
		if (n > (INT_MAX - s[i] + '0') / 10)
			return (false);
		n = n * 10 + s[i] - '0';
		++i;
	}
	return (true);
}

static inline t_status __is_all_valid_integers(int argc, char **argv)
{
	int i;
	int tmp;

	i = 1;
	while (i < argc)
	{
		if (___is_valid_integer(argv[i]) == false)
			return (false);
		++i;
	}
	return (true);
}

static inline t_status _check_argv(int argc, char **argv)
{
	if (__is_all_valid_integers(argc, argv) == false)
		return (INVALID);
	return (VALID);
}

t_status check_args(int argc, char **argv)
{
	if (_check_argc(argc) == INVALID)
		err();
	if (_check_argv(argc, argv) == INVALID)
		err();
}