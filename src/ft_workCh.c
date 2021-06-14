#include "../ft_printf.h"

static void	ft_fillStrCh(char *dest, char *src, t_flags *flags, int sizeDest)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	if (flags->width > len && flags->zero == 1)
		len = flags->width;
	if (flags->minus == 0)
		i = sizeDest - len;
	while (len - 1 > 0)
	{
		dest[i] = '0';
		len--;
		i++;
	}
	dest[i] = *src;
}

char	*ft_workCh(char *str, t_flags *flags)
{
	int		len;
	char	*res;

	if (flags->minus == 1)
		flags->zero = 0;
	len = 1;
	if (flags->width > len)
	{
		len = flags->width;
		res = (char *)malloc(sizeof(char) * len);
	}
	else
		res = (char *)malloc(sizeof(char) * len + 1);
	res[len] = '\0';
	len--;
	while (len > -1)
		res[len--] = ' ';
	flags->tmp = ft_strlen(res);
	ft_fillStrCh(res, str, flags, ft_strlen(res));
	if (flags->format == 'c')
		free(str);
	return (res);
}
