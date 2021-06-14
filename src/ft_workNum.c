#include "../ft_printf.h"

long	ft_checkSign(long long n, t_flags *flags)
{
	if (n < 0)
	{
		flags->sign = "-";
		n = -n;
	}
	return (n);
}

static void	ft_fillStr(char *dest, char *src, t_flags *flags, int sizeDest)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (flags->exact == 0 && *src == '0' && flags->dot == 1 && \
	flags->format != 'p')
		return ;
	if (flags->exact > len)
		len = flags->exact;
	else if (flags->width > len && flags->zero == 1 && flags->dot == 0)
		len = flags->width - ft_strlen(flags->sign);
	if (flags->minus == 0)
		i = sizeDest - len - ft_strlen(flags->sign);
	while (*flags->sign != '\0')
		dest[i++] = *flags->sign++;
	while (len - ft_strlen(src) > 0)
	{
		dest[i] = '0';
		len--;
		i++;
	}
	while (*src != '\0')
		dest[i++] = *src++;
}

static char	*ft_specialCase(char *str)
{
	char	*res;

	res = (char *)malloc(sizeof(char));
	res[0] = '\0';
	free(str);
	return (res);
}

char	*ft_workNum(char *str, t_flags *flags)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	if (flags->exact > len)
		len = flags->exact;
	if (flags->exact == 0 && *str == '0' && flags->dot && flags->width == 0 \
	&& flags->format != 'p')
		return (ft_specialCase(str));
	if (flags->width > len + ft_strlen(flags->sign))
	{
		len = flags->width;
		res = (char *)malloc(sizeof(char) * len);
	}
	else
	{
		len += ft_strlen(flags->sign);
		res = (char *)malloc(sizeof(char) * len + 1);
	}
	res[len--] = '\0';
	while (len > -1)
		res[len--] = ' ';
	ft_fillStr(res, str, flags, ft_strlen(res));
	free(str);
	return (res);
}
