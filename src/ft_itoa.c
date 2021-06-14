#include "../ft_printf.h"

static int	ft_numSize(long n)
{
	int	size;

	if (n < 0)
	{
		n *= -1;
		size = 2;
	}
	else
		size = 1;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_convInt(long num, char *res, int numSize, long long n)
{
	res[numSize--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		res[numSize--] = (num % 10) + '0';
		num /= 10;
	}
}

static void	ft_unsConvInt(unsigned int num, char *res, int numSize)
{
	res[numSize--] = '\0';
	while (num > 0)
	{
		res[numSize--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_unsItoa(unsigned int n)
{
	unsigned int	numSize;
	char			*res;

	numSize = ft_numSize((long)n);
	res = (char *)malloc(sizeof(char) * numSize + 1);
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	ft_unsConvInt(n, res, numSize);
	return (res);
}

char	*ft_itoa(long long n)
{
	int		numSize;
	long	num;
	char	*res;

	numSize = ft_numSize(n);
	num = n;
	res = (char *)malloc(sizeof(char) * numSize + 1);
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	ft_convInt(num, res, numSize, n);
	return (res);
}
