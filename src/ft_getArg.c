#include "../ft_printf.h"

static void	ft_fillStrOfList(t_listInt *list, char *str)
{
	t_listInt	*tmp;
	int			i;

	i = 0;
	while (list != NULL)
	{
		if (list->content >= 0 && list->content <= 9)
			str[i] = list->content + 48;
		else
			str[i] = list->content + 87;
		tmp = list->next;
		free(list);
		list = tmp;
		i++;
	}
	str[i] = '\0';
}

static char	*ft_convertNum(unsigned long long n)
{
	t_listInt	*list;
	char		*str;

	list = ft_lstIntnew((int)(n - ((n / 16) * 16)));
	n /= 16;
	while (n > 15)
	{
		ft_lstintadd_front(&list, ft_lstIntnew((int)(n - ((n / 16) * 16))));
		n /= 16;
	}
	if (n != 0)
		ft_lstintadd_front(&list, ft_lstIntnew((int)n));
	str = (char *)malloc(sizeof(char) * ft_lstintsize(list) + 1);
	ft_fillStrOfList(list, str);
	return (str);
}

static char	*ft_numToChUpCase(unsigned int n)
{
	char	*str;
	int		i;

	str = ft_convertNum(n);
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

static char	*ft_address(unsigned long long n, t_flags *flags)
{
	flags->sign = "0x";
	return (ft_convertNum(n));
}

char	*ft_getArg(char format, va_list arg, t_flags *flags, char *res)
{
	char	*tmp;

	if (format == 's')
	{
		tmp = va_arg(arg, char *);
		if (tmp == NULL)
			return (ft_workStr("(null)", flags, res));
		else
			return ((ft_workStr(tmp, flags, res)));
	}
	if (format == 'd' || format == 'i')
		return (ft_workNum(ft_itoa(ft_checkSign(va_arg(arg, int), flags)), \
		flags));
	if (format == 'c')
		return (ft_workCh(ft_convertChar((char) va_arg(arg, int)), flags));
	if (format == 'u')
		return (ft_workNum(ft_unsItoa(va_arg(arg, unsigned int)), flags));
	if (format == 'p')
		return (ft_workP(ft_address(va_arg(arg, unsigned long long), \
		flags), flags));
	if (format == 'x')
		return (ft_workNum(ft_convertNum(va_arg(arg, unsigned int)), flags));
	if (format == 'X')
		return (ft_workNum(ft_numToChUpCase(va_arg(arg, unsigned int)), flags));
	return (ft_workCh("%", flags));
}
