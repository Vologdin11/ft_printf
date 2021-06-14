#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int		width;
	int		minus;
	int		zero;
	int		tmp;
	int		dot;
	int		exact;
	char	format;
	char	*sign;
}				t_flags;

typedef struct s_listInt
{
	int					content;
	struct s_listInt	*next;
}				t_listInt;

int				ft_printf(const char *str, ...);
char			*ft_itoa(long long n);
void			ft_flagsNew(t_flags *new);
char			*ft_unsItoa(unsigned int n);
char			*ft_convertChar(char c);
int				ft_strlen(const char *str);
t_listInt		*ft_lstIntnew(int content);
void			ft_lstintadd_front(t_listInt **lst, t_listInt *new);
int				ft_lstintsize(t_listInt *lst);
char			*ft_getArg(char format, va_list arg, t_flags *flags, char *res);
char			*ft_workNum(char *str, t_flags *flags);
long			ft_checkSign(long long n, t_flags *flags);
char			*ft_workCh(char *str, t_flags *flags);
char			*ft_workStr(char *str, t_flags *flags, char *res);
void			ft_checkFlags(t_flags *flags);
int				ft_toupper(int ch);
char			*ft_workP(char *str, t_flags *flags);

#endif
