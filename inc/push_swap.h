/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:12:12 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/27 21:21:04 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

// push_swap.c

// libft_utils.c
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
size_t	ft_putnbr_base(int nb, char *base);
size_t	ft_strlen(const char *s);

// stack_utils.c
void	set_stack(t_stack **a, char **argv, size_t len);
void	check_stack(t_stack *a);
t_stack	*get_last(t_stack *x);
t_stack	*get_penult(t_stack *x);

// error_utils.c
void	ft_error(void);
void	check_arg(int argc, char **argv);
void	check_dup(t_stack *a);

// operators.c
void	swap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b, char flag);
void	rotate(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **a, t_stack **b);
#endif
