/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:12:12 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/16 22:09:14 by telufulu         ###   ########.fr       */
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
void	check_stack(t_stack *a, t_stack *b);
void	set_stack(t_stack **a, char **num);
void	check_dup(t_stack *a);
int		is_order(t_stack *x);
int		is_rev_order(t_stack *x);

#endif
