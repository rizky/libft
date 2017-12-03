# ==== Editable ====
NAME:=libft.a

VECTORPATH:=ft_array/
VECTOR:=fta_alloc fta_append fta_new fta_reserve fta_resize fta_trim \
	fta_clear fta_clearf fta_popback fta_iter fta_iteri fta_popindex \
	fta_swap fta_overwrite fta_string fta_replace

FILES=ft_isdigit ft_lstdel ft_lstmerge ft_lstswap ft_memdel ft_putendl_fd ft_strchr ft_strequ ft_strmap ft_strnew ft_strsub\
		ft_atoi ft_isprint ft_lstdelone ft_lstnew ft_memalloc ft_memmove ft_putnbr ft_strclr ft_striter ft_strmapi ft_strnstr ft_strtrim\
		ft_bzero ft_itoa ft_lstfind ft_lstremoveif ft_memccpy ft_memset ft_putnbr_fd ft_strcmp ft_striteri ft_strncat ft_strrchr ft_tolower\
		ft_isalnum ft_lstadd ft_lstiter ft_lstrev ft_memchr ft_putchar ft_putstr ft_strcpy ft_strjoin ft_strncmp ft_strsplit ft_toupper\
		ft_isalpha ft_lstaddlast ft_lstlast ft_lstsize ft_memcmp ft_putchar_fd ft_putstr_fd ft_strdel ft_strlcat ft_strncpy ft_strsplit_tolst\
		ft_isascii ft_lstclear ft_lstmap ft_lstsort ft_memcpy ft_putendl ft_strcat ft_strdup ft_strlen ft_strnequ ft_strstr ft_putlst

# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -I $(HDRPATH)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
FILES+=$(addprefix $(VECTORPATH),$(VECTOR))

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists
MAKEFLAGS+=-j

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo ".\c"
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(CCHPATH)
	@mkdir $(CCHPATH)$(VECTORPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

test:
	@echo "Files :" $(FILES)

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
