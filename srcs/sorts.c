/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:19:49 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/17 01:25:06 by telufulu         ###   ########.fr       */
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

int	get_big(t_stack **a, int big)
{
	int	i;
	t_stack	*aux;

	i = 0;
	aux = (*a);
	while (aux->pos != big)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

int	get_small(t_stack **a)
{
	int		i;
	int		res;
	t_stack	*aux;

	i = INT_MAX;
	aux = (*a);
	while (aux)
	{
		if (aux->pos < i)
			i = aux->pos;
		aux = aux->next;
	}
	res = 0;
	aux = (*a);
	while (aux->pos != i)
	{
		aux = aux->next;
		res++;
	}
	return (res);
}

void	medium_sort(t_stack **a, int big)
{
	int	big_pos;
	t_stack	*b;

	b = 0;
	while (ft_lstsize(*a) > 3 && !is_order(*a))
	{
		big_pos = get_big(a, big);
		while ((*a)->pos != big_pos)
		{
			if (big_pos < big / 2)
				rotate(a, 0);
			else if (big_pos >= big / 2)
				rev_rotate(a, 0);
			if ((*a)->pos == big_pos - 1)
				push(a, &b, 'b');
		}
		if ((*a)->pos == big_pos)
		{	
			push(a, &b, 'b');
			if (b && b->next && b->nb < (b->next)->nb)
				swap(0, &b);
		}
		big--;
	}
	while (b)
		push(a, &b, 'a');
}
