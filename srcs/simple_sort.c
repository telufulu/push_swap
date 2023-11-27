/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:28:59 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/27 16:36:54 by telufulu         ###   ########.fr       */
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
		else if (((*a)->nb > three->nb && (*a)->nb < two->nb))
			rev_rotate(a, 0);
		else if ((*a)->nb > two->nb ||
			((*a)->nb < two->nb && (*a)->nb < three->nb))
			swap(a, 0);
	}
}

void	medium_sort(t_stack **a, t_stack **b)
{
	t_stack	*two;
	t_stack	*last;

	two = 0;
	last = 0;
	while (!is_order(*a) && ft_lstsize(*a) > 3)
	{
		two = (*a)->next;
		last = ft_lstlast(*a);
		if ((*a)->pos == 0 || (*a)->pos == 1)
			push(a, b, 'b');
		else if (two->pos == 0 || two->pos == 1)
			swap(a, 0);
		else if (last->pos == 0 || last->pos == 1)
			rev_rotate(a, 0);
		else
			rotate(a, 0);
	}
	small_sort(a);
	if (*b && (*b)->next && (*b)->pos < ((*b)->next)->pos)
		swap(0, b);
	while (*b)
		push(a, b, 'a');
}
