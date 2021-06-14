#include "../ft_printf.h"

static int	ft_outStr(char *str, t_flags *flags)
{
	unsigned int	i;

	i = 0;
	if (flags->format == 'c' && flags->tmp > 0)
	{
		write(1, str, flags->tmp);
		free(str);
		return (flags->tmp);
	}
	else
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	i = ft_strlen(str);
	free(str);
	return (i);
}

static int	ft_parseNum(const char *str, int *i)
{
	int	res;

	res = 0;
	while (str[*i] >= '0' && str[*i] <= '9' && str[*i] != '\0')
	{
		res = res * 10 + (str[*i] - '0');
		*i += 1;
	}
	*i -= 1;
	if (res > -1)
		return (res);
	else
		return (0);
}

static void	ft_dopParseConditions(const char *str, int *i, \
t_flags *flags, va_list arg)
{
	if (str[*i] == '*')
	{
		if (flags->dot == 1)
			flags->exact = va_arg(arg, int);
		else
			flags->width = va_arg(arg, int);
	}
	else
	{
		if (flags->dot == 1)
			flags->exact = ft_parseNum(str, i);
		else
			flags->width = ft_parseNum(str, i);
	}
}

static int	ft_parse(const char *str, int *i, va_list arg, char *res)
{
	t_flags	flags;

	*i += 1;
	ft_flagsNew(&flags);
	while (str[*i] != '\0')
	{
		if (str[*i] == '.')
			flags.dot = 1;
		else if (str[*i] == '0')
			flags.zero = 1;
		else if (str[*i] == '-' && flags.dot == 0)
			flags.minus = 1;
		else if (str[*i] == '*' || (str[*i] >= '0' && str[*i] <= '9'))
			ft_dopParseConditions(str, i, &flags, arg);
		else
		{
			flags.format = str[*i];
			break ;
		}
		*i += 1;
	}
	ft_checkFlags(&flags);
	res = ft_getArg(flags.format, arg, &flags, res);
	return (ft_outStr(res, &flags));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	char	*res;
	va_list	arg;

	i = 0;
	count = 0;
	res = "";
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count += ft_parse(str, &i, arg, res);
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
