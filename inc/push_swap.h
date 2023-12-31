/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:12:12 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/18 16:41:38 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"

/*
	borrar stdio.h
*/
# include "libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>

// push_swap.c

// stack_utils.c
void	rename_nbs(t_stack **a);
void	set_stack(t_stack **a, char **num);
int		is_order(t_stack *x);

// checks.c
void	check_stack(t_stack *a, t_stack *b);
void	check_dup(t_stack *a);

// operators.c
void	swap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b, char flag);
void	rotate(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **a, t_stack **b);

// big_sort.c
void	push_b_stack(t_stack **a, t_stack **b, size_t big);
size_t	num_pos(t_stack *x, size_t big);
void	final_sort(t_stack **a, t_stack **b);
void	big_sort(t_stack **a, t_stack **b, size_t big);

// simple_sort.c
void	small_sort(t_stack **a, t_stack **b);
void	medium_sort(t_stack **a, t_stack **b);
void	push_small(t_stack **a, t_stack **b, size_t small);
size_t	get_small(t_stack *x);
#endif
