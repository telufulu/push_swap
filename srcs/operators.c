/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:11:21 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/26 17:51:22 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, t_stack **b)
{
	t_stack	*last;
	int		aux;

	if (a && b)
		write(1, "ss\n", 3);
	if (a)
	{
		last = get_last((*a));
		aux = last->nb;
		last->nb = (*a)->nb;
		(*a)->nb = aux;
		if (!b)
			write(1, "sa\n", 3);
	}
	if (b)
	{
		last = get_last((*b));
		aux = last->nb;
		last->nb = (*b)->nb;
		(*b)->nb = aux;
		if (!a)
			write(1, "sb\n", 3);
	}
}