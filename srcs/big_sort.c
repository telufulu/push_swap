/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:19:49 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/18 16:37:33 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_stack(t_stack **a, t_stack **b, size_t big)
{
	size_t	i;
	t_stack	*last;

	if (big > 100)
		i = big / 32;
	else if (big > 20 && big <= 100)
		i = big / 11;
	else
		i = big / 5;
	while ((*a)->next && ft_lstsize(*a) > 5)
	{
		last = ft_lstlast(*a);
		if ((*a)->pos > i || (*a)->pos > big - 5)
			rotate(a, 0);
		else if ((*a)->pos <= i && i++)
		{
			push(a, b, 'b');
			if ((*b)->next && (*b)->pos < ((*b)->next)->pos)
				swap(0, b);
		}
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
