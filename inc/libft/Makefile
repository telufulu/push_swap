NAME				=	libft.a
CC					=	cc
INC					=	inc/
CFLAGS				=	-Wall -Werror -Wextra -I $(INC)
SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
SRCS_FILES			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
						ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
						ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
						ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
						ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
						ft_atoi.c ft_calloc.c ft_strdup.c \
						ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
						ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
						ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
						ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
						ft_lstsize_bonus.c ft_lstlast_bonus.c \
						ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
						ft_lstclear_bonus.c ft_lstiter_bonus.c \
						ft_lstmap_bonus.c ft_putnbr_base.c
SRCS_DIR			=	srcs/
OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_FILES			=	$(SRCS_FILES:%.c=%.o)
OBJS_DIR			=	objs/

all:	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJS) $(OBJS_BONUS) re clean fclean
.PHONY: all bonus clean fclean re
