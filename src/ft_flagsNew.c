#include "../ft_printf.h"

int	ft_lstintsize(t_listInt *lst)
{
	int			count;
	t_listInt	*tmp;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_lstintadd_front(t_listInt **lst, t_listInt *new)
{
	new->next = lst[0];
	lst[0] = new;
}

t_listInt	*ft_lstIntnew(int content)
{
	t_listInt	*new;

	new = (t_listInt *)malloc(sizeof(t_listInt));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_flagsNew(t_flags *new)
{
	new->tmp = 0;
	new->width = 0;
	new->minus = 0;
	new->zero = 0;
	new->dot = 0;
	new->exact = 0;
	new->format = '0';
	new->sign = "\0";
}
