#include "../ft_printf.h"

static void	ft_fillStr(char *dest, char *src, t_flags *flags, int sizeDest)
{
	int	i;
	int	len;

	i = 0;
	if (*src == '0' && flags->dot == 1 && flags->exact == 0)
		len = 0;
	else
		len = ft_strlen(src);
	if (flags->exact > len)
		len = flags->exact;
	else if (flags->width > len && flags->zero == 1 && flags->dot == 0)
		len = flags->width - ft_strlen(flags->sign);
	if (flags->minus == 0)
		i = sizeDest - len - ft_strlen(flags->sign);
	while (*flags->sign != '\0')
		dest[i++] = *flags->sign++;
	while (len - ft_strlen(src) > 0 && i < sizeDest)
	{
		dest[i] = '0';
		len--;
		i++;
	}
	while (*src != '\0' && i < sizeDest)
		dest[i++] = *src++;
}

char	*ft_workP(char *str, t_flags *flags)
{
	int		len;
	char	*res;

	if (*str == '0' && flags->dot == 1 && flags->exact == 0)
		len = 0;
	else
		len = ft_strlen(str);
	if (flags->exact > len)
		len = flags->exact;
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
