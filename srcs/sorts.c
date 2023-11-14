/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/14 19:09:36 by telufulu         ###   ########.fr       */
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
void	get_small(int *small_one, int *small_two, t_stack *aux)
{
	t_stack	*a;

	a = aux;
	*small_one = INT_MAX;
	while (aux)
	{
		if (aux->nb < *small_one)
			*small_one = aux->nb;
		aux = aux->next;
	}
	aux  = a;
	*small_two = INT_MAX;
	while (aux)
	{
		if (aux->nb < *small_two && aux->nb > *small_one)
			*small_two = aux->nb;
		aux = aux->next;
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		small_one;
	int		small_two;
	t_stack	*last;
	t_stack	*pen;
	
	get_small(&small_one, &small_two, *a);
	while (!is_order(*a))
	{
		pen = get_penult(*a);
		last = pen->next;
		if (pen->nb == small_two || last->nb == small_two)
			rev_rotate(a, 0);
		else if (pen->nb == small_one || last->nb == small_one)
			rev_rotate(a, 0);
		else if (((*a)->nb == small_one || (*a)->nb == small_two))
			push(a, b, 'b');
		else
			rotate(a, 0);
		if (stack_len(*a) == 3)
			sort_three(a);
	}	
	push(a, b, 'a');
	push(a, b, 'a');
	if ((*a)->nb > ((*a)->next)->nb)
		swap(a, 0);
}

void	sort_three(t_stack **a)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_order(*a))
	{
		two = (*a)->next;
		three = two->next;
		if ((*a)->nb > two->nb)
			swap(a, 0);
		else if (((*a)->nb > three->nb && (*a)->nb > two->nb))
			rotate(a, 0);
		else if ((three->nb < (*a)->nb && three->nb < two->nb) ||
			((*a)->nb < two->nb && two->nb > three->nb))
			rev_rotate(a, 0);
	}
}
