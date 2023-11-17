/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:12:12 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/17 01:12:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
/*
 * borrar ^|^
 */

# include "libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

// push_swap.c

// stack_utils.c
void	rename_nbs(t_stack **a);
void	set_stack(t_stack **a, char **num);
int		is_order(t_stack *x);
int		is_rev_order(t_stack *x);

// checks.c
void	check_stack(t_stack *a, t_stack *b);
void	check_dup(t_stack *a);

// operators.c
void	swap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b, char flag);
void	rotate(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **a, t_stack **b);

// sorts.c
void	small_sort(t_stack **a);
int		get_big(t_stack **a, int big);
void	medium_sort(t_stack **a, int big);

#endif
