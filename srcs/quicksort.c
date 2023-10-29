/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:59:36 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/29 19:14:53 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *a)
{
	t_stack	*mid;
	t_stack	*last;
	size_t	len;
	size_t	i;

	i = 0;
	len = stack_len(a);
	last = (get_penult(a))->next;
	mid = a;
	while (i++ < (len / 2))
		mid = mid->next;
	return ((a->nb + mid->nb + last->nb) / 3);
}

void	quicksort(t_stack **a)
{
	t_stack	*b;
	int		pivot;

	b = 0;
	while (stack_len(*a) > stack_len(b))
	{
		pivot = get_pivot(*a);
		if ((*a)->nb > pivot)
		{
			printf("pivot: %i\n", pivot);
			push(a, &b, 'b');
		}
		else
			rotate(a, 0);
		check_stack(*a, b);
	}
}
