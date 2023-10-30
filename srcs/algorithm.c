/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:59:36 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/30 11:03:33 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_b(t_stack **a, t_stack **b)
{
	t_stack	*next_a;
	t_stack	*next_b;

	while (!is_order(*b))
	{
		sleep(2);
		check_stack(*a, *b);
		next_a = (*a)->next;
		next_b = (*b)->next;
		if (!is_order(*a) && !is_order(*b) && (*a)->nb > next_a->nb && \
			(*b)->nb < next_b->nb)
			swap(a, b);
		else if (!is_order(*b) && (*b)->nb > next_b->nb)
			swap(0, b);
		else if (!is_order(*a) && (*a)->nb > next_a->nb)
			swap(a, 0);
		if (!is_order(*a) && !is_order(*b))
			rotate(a, b);
		else if (!is_order(*a))
			rotate(a, 0);
		else if (!is_order(*b))
			rotate(0, b);
	}
}

void	order_a(t_stack **a, t_stack **b)
{
	t_stack	*next_a;
	t_stack	*next_b;

	while (!is_order(*a))
	{
		sleep(2);
		check_stack(*a, *b);
		next_a = (*a)->next;
		next_b = (*b)->next;
		if (!is_order(*a) && !is_order(*b) && (*a)->nb < next_a->nb && \
			(*b)->nb < next_b->nb)
			swap(a, b);
		else if (!is_order(*b) && (*b)->nb < next_b->nb)
			swap(0, b);
		else if (!is_order(*a) && (*a)->nb < next_a->nb)
			swap(a, 0);
		if (!is_order(*a) && !is_order(*b))
			rotate(a, b);
		else if (!is_order(*a))
			rotate(a, 0);
		else if (!is_order(*b))
			rotate(0, b);
	}
}

void	my_bubblesort(t_stack **a, t_stack **b)
{
	write(1, "bubble\n", 7);
	order_a(a, b);
	order_b(a, b);
	while ((*b)->next)
	{
		if ((*b)->nb > ((*b)->next)->nb)
			swap(0, b);
		push(a, b, 'a');
		order_a(a, b);
	}
	push(a, b, 'a');
	rotate(a, 0);
}

void	my_mergesort(t_stack **a, t_stack **b)
{
	int		pivot;

	write(1, "merge\n", 6);
	while (stack_len(*a) > 3)
	{
		check_stack(*a, *b);
		pivot = get_pivot(*a);
		if ((*a)->nb > pivot)
		{
			printf("pivot: %i\n", pivot);
			push(a, b, 'b');
		}
		else
			rotate(a, 0);
	}
}

void	algorithm(t_stack **a, t_stack **b)
{
	my_mergesort(a, b);
	if (stack_len(*a) > stack_len(*b))
		algorithm(a, b);
	my_bubblesort(a, b);
	check_stack(*a, *b);
}
