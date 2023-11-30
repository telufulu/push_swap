/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:28:59 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/30 19:56:59 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a, t_stack **b)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_order(*a))
	{
		two = (*a)->next;
		three = two->next;
		if (!three || ((*a)->nb > two->nb && (*a)->nb > three->nb))
			rotate(a, 0);
		else if (((*a)->nb > three->nb && (*a)->nb < two->nb))
			rev_rotate(a, 0);
		else if ((*a)->nb > two->nb || ((*a)->nb < two->nb && \
					(*a)->nb < three->nb))
		{
			if (*b && (*b)->next && (*b)->pos < ((*b)->next)->pos)
				swap(a, b);
			else
				swap(a, 0);
		}
	}
}

size_t	get_small(t_stack *x)
{
	size_t	res;

	res = UINT_MAX;
	while (x)
	{
		if (x->pos < res)
			res = x->pos;
		x = x->next;
	}
	return (res);
}

void	medium_sort(t_stack **a, t_stack **b)
{
	t_stack	*two;
	t_stack	*last;
	size_t	small;

	two = 0;
	last = 0;
	small = get_small(*a);
	while (!is_order(*a) && ft_lstsize(*a) > 3)
	{
		two = (*a)->next;
		last = ft_lstlast(*a);
		if ((*a)->pos == small || (*a)->pos == small + 1)
			push(a, b, 'b');
		else if (((*a)->pos == two->pos + 1) || \
				two->pos == small || two->pos == small + 1)
			swap(a, 0);
		else if (last->pos == small || last->pos == small + 1)
			rev_rotate(a, 0);
		else
			rotate(a, 0);
	}
	small_sort(a, b);
	if (*b && (*b)->next && (*b)->pos < ((*b)->next)->pos)
		swap(0, b);
	while (*b)
		push(a, b, 'a');
}
