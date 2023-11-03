/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:04 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/03 17:13:55 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *x)
{
	size_t	len;
	size_t	i;
	t_stack	*mid;
	t_stack	*last;

	i = 0;
	len = stack_len(x) / 2;
	last = (get_penult(x))->next;
	mid = x;
	while (i++ < len)
		mid = mid->next;
	return ((x->nb + mid->nb + last->nb) / 3);
}

void	ft_mergesort(t_stack **a, t_stack **b)
{
	int	pivot;

	while (stack_len(*a) > stack_len(*b))
	{
		pivot = get_pivot(*a);
		if ((*a)->nb >= pivot)
		{
			push(a, b, 'b');
			if ((*b)->next && (*b)->nb > ((*b)->next)->nb)
				swap(0, b);
		}
		else
			rotate(a, 0);
	}
}

void	ft_bubblesort_a(t_stack **a)
{
	t_stack	*two;
	t_stack	*three;

	while ((*a) && (*a)->next && !is_order(*a))
	{
		two = (*a)->next;
		three = (get_penult(*a))->next;
		if ((*a)->nb > two->nb)
			swap(a, 0);
		else if (three->nb < (*a)->nb && three->nb < two->nb)
			rev_rotate(a, 0);
		else if (three->nb > (*a)->nb && three->nb > two->nb)
			rotate(a, 0);
	}
}

void	ft_bubblesort_b(t_stack **a, t_stack **b)
{
	t_stack	*two;
	t_stack	*last;

	while ((*b)->next)
	{
		two = (*b)->next;
		last = (get_penult(*b))->next;
		if (two && two->nb < (*b)->nb)
			swap(0, b);
		else if (last && last->nb < (*b)->nb)
			rev_rotate(0, b);
		push(a, b, 'a');
		// MEJORABLE
		if ((*a)->nb < ((get_penult(*a))->next)->nb)
		{
			rev_rotate(a, 0);
			swap(a, 0);
			rotate(a, 0);
		}
		rotate(a, 0);
	}
	push(a, b, 'a');
	rotate(a, 0);
}

void	algorithm(t_stack **a)
{
	t_stack	*b;

	b = 0;
	ft_mergesort(a, &b);
	if (stack_len(*a) > 3)
	{
		algorithm(a);
	}
	if (!is_order(*a))
	{
		ft_bubblesort_a(a);
	}
	if (b)
		ft_bubblesort_b(a, &b);
}
