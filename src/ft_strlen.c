#include "../ft_printf.h"

int	ft_toupper(int ch)
{
	if (ch > 96 && ch < 123)
		return (ch - 32);
	return (ch);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
