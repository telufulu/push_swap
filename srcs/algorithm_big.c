/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/08 01:39:11 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_push(t_stack **a, t_stack **b)
{
	while ((*b) && (*b)->next)
	{
		push(a, b, 'a');
		ft_bubblesort_a(a);
		if (*b)
			push(a, b, 'a');
		ft_bubblesort_a(a);
	}
}

void	algorithm_big(t_stack **a)
{
	t_stack *b;

	b = 0;
	ft_mergesort(a, &b);
	if (!is_rev_order(b))
		ft_bubblesort_b(&b);
	if (stack_len(*a) > 3)
		algorithm_big(a);
	ft_bubblesort_a(a);
	final_push(a, &b);
}
