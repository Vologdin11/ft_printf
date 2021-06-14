NAME = libftprintf.a

SRCS =	src/ft_printf.c \
	src/ft_itoa.c \
	src/ft_flagsNew.c \
	src/ft_strlen.c \
	src/ft_convertChar.c \
	src/ft_getArg.c \
	src/ft_workNum.c \
	src/ft_workCh.c \
	src/ft_workStr.c \
	src/ft_workP.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all