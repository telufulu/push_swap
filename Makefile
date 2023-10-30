NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -I $(INC)
INC				=	inc/

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_FILES		=	$(SRCS_FILES:%.c=%.o)
SRCS_FILES		=	push_swap.c libft_utils.c stack_utils.c error_utils.c \
					operators.c algorithm.c algorithm_utils.c

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete
	find . -name "*.gch" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.SILENT: all clean fclean re $(NAME) $(OBJS)
.PHONY: all clean fclean re	
