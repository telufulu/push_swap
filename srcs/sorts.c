/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/08 11:26:04 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *x)
{
	int			i;
	unsigned long long int res;
	
	i = 0;
	res = 0;
	while (x)
	{
		i++;
		res += x->nb;
		x = x->next;
	}
	res /= i;
	return (res);
}

void	sort_five(t_stack **a)
{
	t_stack *b;
	int		pivot;

	b = 0;
	pivot = get_pivot(*a);
	while (!is_order(*a) && stack_len(*a) > 3)
	{
		if ((get_penult(*a)->next)->nb <= pivot)
			rev_rotate(a, 0);
		else if ((*a)->nb > pivot)
			rotate(a, 0);
		else if ((*a)->nb <= pivot)
			push(a, &b, 'b');
		else if ((*a)->nb > ((*a)->next)->nb)
		{
			if (b && b->next && b->nb > (b->next)->nb)
				swap(a, &b);
			else
				swap(a, 0);
		}
	}
	ft_bubblesort_a(a);
	while (b && !is_order(*a))
	{
		if ((*a)->nb > ((*a)->next)->nb)
		{
			if (b->next && (b->next)->nb < b->nb)
				swap(0, &b);
			swap(a, 0);
		}
		if (b->next && (b->next)->nb < b->nb)
			swap(0, &b);
		push(a, &b, 'a');
	}
}

void	ft_mergesort(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = get_pivot(*a);
	while (stack_len(*a) > 3 && stack_len(*b) < 3)
	{
		if ((get_penult(*a)->next)->nb < pivot)
			rev_rotate(a, 0);
		if ((*a)->nb >= pivot)
			rotate(a, 0);
		else
		{
			push(a, b, 'b');
			pivot = get_pivot(*a);
			if ((*b)->next && (*b)->nb > ((*b)->next)->nb)
			{
				if ((*a)->nb > ((*a)->next)->nb)
					swap(a, b);
				else
					swap(0, b);
			}
		}
	}
}

void	ft_bubblesort_b(t_stack **b)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_rev_order(*b))
	{
		two = (*b)->next;
		three = two->next;
		if ((*b)->nb > two->nb && (*b)->nb > three->nb)
			rotate(0, b);
		else if ((*b)->nb < two->nb)
			swap(0, b);
		else if (three->nb > two->nb && (*b)->nb > two->nb)
			rev_rotate(0, b);
	}
}

void	ft_bubblesort_a(t_stack **a)
{
	t_stack	*two;
	t_stack	*three;
	t_stack	*last;

	while (!is_order(*a))
	{
		two = (*a)->next;
		three = two->next;
		last = (get_penult(*a))->next;
		if (last->nb < (*a)->nb || last->nb < two->nb)
			rev_rotate(a, 0);
		else if (three->nb < two->nb)
			rotate(a, 0);
		else if ((*a)->nb > two->nb)
			swap(a, 0);
	}
}
