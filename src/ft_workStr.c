#include "../ft_printf.h"

static void	ft_fillStrS(char *dest, char *src, t_flags *flags, int sizeDest)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (flags->exact < len && flags->dot == 1)
		len = flags->exact;
	else if (flags->width > len && flags->zero == 1)
		len = flags->width;
	if (flags->minus == 0)
		i = sizeDest - len;
	while (len-- - ft_strlen(src) > 0)
		dest[i++] = '0';
	if (flags->dot == 1)
	{
		while (flags->exact != 0 && *src != '\0')
		{
			dest[i++] = *src++;
			flags->exact--;
		}
	}
	else
		while (*src != '\0')
			dest[i++] = *src++;
}

void	ft_checkFlags(t_flags *flags)
{
	if (flags->exact < 0)
		flags->dot = 0;
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
	}
	if (flags->minus == 1 || flags->dot == 1)
		flags->zero = 0;
}

char	*ft_workStr(char *str, t_flags *flags, char *res)
{
	int		len;

	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->exact < 0)
		flags->exact = 0;
	len = ft_strlen(str);
	if (flags->exact < len && flags->dot == 1)
		len = flags->exact;
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
	{
		res[len] = ' ';
		len--;
	}
	ft_fillStrS(res, str, flags, ft_strlen(res));
	return (res);
}
