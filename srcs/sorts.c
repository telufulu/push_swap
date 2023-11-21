/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:19:49 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/21 21:07:44 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_order(*a))
	{
		two = (*a)->next;
		three = two->next;
		if ((*a)->nb > two->nb && (*a)->nb > three->nb)
			rotate(a, 0);
		else if (((*a)->nb > three->nb && two->nb < three->nb) || 
			((*a)->nb > three->nb && two->nb > three->nb))
			rev_rotate(a, 0);
		else if ((*a)->nb > two->nb || 
			((*a)->nb < two->nb && (*a)->nb < three->nb))
			swap(a, 0);
	}
}

void	push_b_stack(t_stack **a, t_stack **b)
{
	size_t	i;
	size_t	x;
	t_stack	*two;
	t_stack *last;

	i = 10;
	while (*a)
	{
		two = (*a)->next;
		last = ft_lstlast(*a);
		x = ((i / 10) % 10) * 10;
		if ((*a)->pos <= x && i++)
			push(a, b, 'b');
		else if (two->pos <= x)
			swap(a, 0);
		else if (last->pos <= x)
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

	big = ft_lstsize(*b);
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

void	big_sort(t_stack **a)
{
	t_stack	*b;

	b = 0;
	push_b_stack(a, &b);
	final_sort(a, &b);
	check_stack(*a, b);
}
