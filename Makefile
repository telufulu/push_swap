NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -I $(INC)
INC				=	inc/

LIBFT_DIR		=	$(INC)libft/
LIBFT			=	$(LIBFT_DIR)libft.a

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_FILES		=	$(SRCS_FILES:%.c=%.o)
SRCS_FILES		=	push_swap.c checks.c stack_utils.c operators.c \
					big_sort.c simple_sort.c

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

generator:
	$(CC) $(CFLAGS) test/generator.c -o $@

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete
	find . -name "*.gch" -delete
	rm -f generator

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

.SILENT: all clean fclean re generator $(NAME) $(OBJS) $(LIBFT)
.PHONY: all clean fclean re	generator
