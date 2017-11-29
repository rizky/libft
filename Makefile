NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERS = -I libft.h
SRC = 	ft_isdigit.c ft_lstdel.c ft_lstmerge.c ft_lstswap.c ft_memdel.c ft_putendl_fd.c ft_strchr.c ft_strequ.c ft_strmap.c ft_strnew.c ft_strsub.c\
		ft_atoi.c ft_isprint.c ft_lstdelone.c ft_lstnew.c ft_memalloc.c ft_memmove.c ft_putnbr.c ft_strclr.c ft_striter.c ft_strmapi.c ft_strnstr.c ft_strtrim.c\
		ft_bzero.c ft_itoa.c ft_lstfind.c ft_lstremoveif.c ft_memccpy.c ft_memset.c ft_putnbr_fd.c ft_strcmp.c ft_striteri.c ft_strncat.c ft_strrchr.c ft_tolower.c\
		ft_isalnum.c ft_lstadd.c ft_lstiter.c ft_lstrev.c ft_memchr.c ft_putchar.c ft_putstr.c ft_strcpy.c ft_strjoin.c ft_strncmp.c ft_strsplit.c ft_toupper.c\
		ft_isalpha.c ft_lstaddlast.c ft_lstlast.c ft_lstsize.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c ft_strdel.c ft_strlcat.c ft_strncpy.c ft_strsplit_tolst.c\
		ft_isascii.c ft_lstclear.c ft_lstmap.c ft_lstsort.c ft_memcpy.c ft_putendl.c ft_strcat.c ft_strdup.c ft_strlen.c ft_strnequ.c ft_strstr.c ft_putlst.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) -c $(CFLAGS) $(SRC) $(HEADERS)
	@ar rc $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all