/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:11:21 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/09 15:31:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (a && (*a)->next && b && (*b)->next)
		write(1, "ss\n", 3);
	if (a && (*a)->next)
	{
		aux = (*a)->next;
		(*a)->next = aux->next;
		aux->next = (*a);
		(*a) = aux;
		if (!b)
			write(1, "sa\n", 3);
	}
	if (b && (*b)->next)
	{
		aux = (*b)->next;
		(*b)->next = aux->next;
		aux->next = (*b);
		(*b) = aux;
		if (!a)
			write(1, "sb\n", 3);
	}
}

void	push(t_stack **a, t_stack **b, char flag)
{
	t_stack	*aux;

	if (flag == 'a' && *b)
	{
		aux = (*b);
		(*b) = (*b)->next;
		aux->next = (*a);
		(*a) = aux;
		write(1, "pa\n", 3);
	}
	else if (flag == 'b' && *a)
	{
		aux = (*a);
		(*a) = (*a)->next;
		aux->next = (*b);
		(*b) = aux;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*aux;

	if (a && (*a)->next && b && (*b)->next)
		write(1, "rr\n", 3);
	if (a && (*a)->next)
	{
		last = (get_penult((*a)))->next;
		aux = (*a);
		(*a) = (*a)->next;
		last->next = aux;
		aux->next = 0;
		if (!b)
			write(1, "ra\n", 3);
	}
	if (b && (*b)->next)
	{
		last = (get_penult((*b)))->next;
		aux = (*b);
		(*b) = (*b)->next;
		last->next = aux;
		aux->next = 0;
		if (!a)
			write(1, "rb\n", 3);
	}
}

void	rev_rotate(t_stack **a, t_stack **b)
{
	t_stack	*last;

	if (a && b)
		write(1, "rrr\n", 4);
	if (a)
	{
		last = (get_penult((*a)))->next;
		(get_penult((*a)))->next = 0;
		last->next = (*a);
		(*a) = last;
		if (!b)
			write(1, "rra\n", 4);
	}
	if (b)
	{
		last = (get_penult((*b)))->next;
		(get_penult((*b)))->next = 0;
		last->next = (*b);
		(*b) = last;
		if (!a)
			write(1, "rrb\n", 4);
	}
}
