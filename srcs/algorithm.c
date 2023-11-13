/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/13 23:47:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_big(int *big_one, int *big_two, t_stack *aux)
{
	t_stack	*a;

	a = aux;
	*big_one = 0;
	while (aux)
	{
		if (aux->nb > *big_one)
			*big_one = aux->nb;
		aux = aux->next;
	}
	aux  = a;
	*big_two = 0;
	while (aux)
	{
		if (aux->nb > *big_two && aux->nb < *big_one)
			*big_two = aux->nb;
		aux = aux->next;
	}
}

void	sort_five_b(t_stack **a, t_stack **b)
{
	int		big_one;
	int		big_two;
	t_stack	*last;
	t_stack	*pen;
	
	get_big(&big_one, &big_two, *b);
	while (!is_rev_order(*b))
	{
		pen = get_penult(*b);
		last = pen->next;
		check_stack(*a, *b);
		sleep(1);
		if (pen->nb == big_two || last->nb == big_two)
			rev_rotate(0, b);
		else if (pen->nb == big_one || last->nb == big_one)
			rev_rotate(0, b);
		else if (((*b)->nb == big_one || (*b)->nb == big_two))
			push(a, b, 'a');
		else
			rotate(0, b);
		if (stack_len(*b) == 3)
			sort_three_b(b);
	}	
	push(a, b, 'b');
	push(a, b, 'b');
	check_stack(0, *b);
	sleep(1);
	if ((*b)->nb < ((*b)->next)->nb)
		swap(0, b);
	check_stack(0, *b);
	sleep(1);
}

void	sort_three_b(t_stack **b)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_rev_order(*b))
	{
		check_stack(0, *b);
		sleep(1);
		two = (*b)->next;
		three = two->next;
		if ((*b)->nb < two->nb)
			swap(0, b);
		else if (three->nb > (*b)->nb && three->nb > two->nb)
			rev_rotate(0, b);
		else if (((*b)->nb < (three->nb && two->nb)) || three->nb > two->nb)
			rotate(0, b);
	}
}

void	ft_mergesort(t_stack **a, t_stack **b)
{
	int	pivot;

	check_stack(*a, *b);
	sleep(1);
	while (stack_len(*b) <= 5)
	{
		pivot = get_pivot(*a);
		if ((get_penult(*a)->next)->nb <= pivot)
			rev_rotate(a, 0);
		else if (((*a)->next)->nb <= pivot)
			swap(a, 0);
		if ((*a)->nb <= pivot)
			push(a, b, 'b');
		else
			rotate(a, 0);
		check_stack(*a, *b);
		sleep(1);
	}
	if (stack_len(*a) <= 5 && !is_order(*a))
		sort_five(a, b);
	else if (stack_len(*a) > 5)
		ft_mergesort(a, b);
	check_stack(*a, *b);
	sleep(1);
	if (!is_rev_order(*b))
		sort_five_b(a, b);
	while (*b)
	{
		if ((*a)->nb < (*b)->nb)
			push(a, b, 'b');
		if ((*b)->nb < ((*b)->next)->nb)
			swap(0, b);
		push(a, b, 'a');
	}
}
