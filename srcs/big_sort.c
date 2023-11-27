/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:19:49 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/27 17:23:14 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_stack(t_stack **a, t_stack **b)
{
	size_t	i;
	size_t	x;
	size_t 	big;
	t_stack *last;

	big = ft_lstsize(*a) - 1;
	i = 10;
	while ((*a)->next)
	{
		last = ft_lstlast(*a);
		x = (i / 10) * 10;
		if ((*a)->pos == big)
			rotate(a, 0);
		else if ((*a)->pos <= x && i++)
		{
			push(a, b, 'b');
			if (i > 10 && !ft_isodd(i / 10))
				rotate(0, b);
		}
		else if (last->pos < x)
			rev_rotate(a, 0);
		else
			rotate(a, 0);
	}
}

size_t	num_pos(t_stack *x, size_t big)
{
	size_t	i;

	i = 1;
	while (x)
	{
		if (x->pos == big)
			return (i);
		x = x->next;
		i++;
	}
	return (i);
}

void	final_sort(t_stack **a, t_stack **b)
{
	size_t	big;

	big = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b)->pos == big)
		{
			push(a, b, 'a');
			big--;
		}
		else if (num_pos(*b, big) <= big / 2)
			rotate(0, b);
		else
			rev_rotate(0, b);
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	push_b_stack(a, b);
	final_sort(a, b);
}
