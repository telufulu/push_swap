/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/04 20:54:19 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	get_pivot(t_stack *x)
{
	size_t		len;
	size_t		i;
	long int	res;
	t_stack		*mid;
	t_stack		*last;

	i = 0;
	len = stack_len(x) / 2;
	last = (get_penult(x))->next;
	mid = x;
	while (i++ < len)
		mid = mid->next;
	res = (x->nb + mid->nb + last->nb) / 3;
	if (res < 0)
		res *= -1;
	return (res);
}

void	ft_mergesort(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = get_pivot(*a);
	while (stack_len(*a) > 3 && stack_len(*b) < 3)
	{
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
		three = (get_penult(*b))->next;
		if ((*b)->nb > two->nb && (*b)->nb > three->nb)
			rotate(0, b);
		else if (three->nb > two->nb && (*b)->nb > two->nb)
			rev_rotate(0, b);
		else if ((*b)->nb < two->nb)
			swap(0, b);
	}
}

void	ft_bubblesort_a(t_stack **a)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_order(*a))
	{
		two = (*a)->next;
		three = (get_penult(*a))->next;
		if ((*a)->nb > two->nb && (*a)->nb > three->nb)
			rotate(a, 0);
		else if (three->nb < two->nb && (*a)->nb < two->nb)
			rev_rotate(a, 0);
		else if ((*a)->nb > two->nb)
			swap(a, 0);
	}
}

void	final_push(t_stack **a, t_stack **b)
{
	t_stack	*two;
	t_stack	*three;
	
	while ((*b) && (*b)->next)
	{
		push(a, b, 'a');
		if (!is_order(*a))
		{
			two = (*a)->next;
			three = two->next;
			if ((*a)->nb > two->nb)
				swap(a, 0);
			// SIGUE POR AQUI
			if (!is_order(*a))
				ft_error(1);
		}
		check_stack(*a, *b);
		sleep(1);
		if (*b)
			push(a, b, 'a');
	}
}

void	algorithm(t_stack **a)
{
	t_stack *b;

	b = 0;
	ft_mergesort(a, &b);
	if (!is_rev_order(b))
		ft_bubblesort_b(&b);
	if (stack_len(*a) > 3)
		algorithm(a);
	ft_bubblesort_a(a);
	final_push(a, &b);
}
