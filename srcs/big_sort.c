/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:19:49 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/05 21:31:26 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_stack(t_stack **a, t_stack **b, size_t big)
{
	size_t	i;
	t_stack	*last;

	i = big / 10;
	while ((*a)->next && ft_lstsize(*a) > 5)
	{
		last = ft_lstlast(*a);
		if ((*a)->pos > big - 5)
			rotate(a, 0);
		else if ((*a)->pos <= i)
		{
			push(a, b, 'b');
			if (!ft_isodd(i))
				rotate(0, b);
			i++;
		}
		else if (last->pos <= i)
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
		if ((*a)->pos > ((*a)->next)->pos)
		{
			if (((*b)->next)->pos == (big || big - 1))
				swap(a, b);
			else
				swap(a, 0);
		}
		if ((*b)->pos == big)
		{
			push(a, b, 'a');
			big--;
		}
		else if ((*b)->pos - 1 == big)
			push(a, b, 'a');
		else if (num_pos(*b, big) < big / 2)
			rotate(0, b);
		else
			rev_rotate(0, b);
	}
}

void	big_sort(t_stack **a, t_stack **b, size_t big)
{
	push_b_stack(a, b, big);
	medium_sort(a, b);
	final_sort(a, b);
}
