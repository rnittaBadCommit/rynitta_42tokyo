int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}
