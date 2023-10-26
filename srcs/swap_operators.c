/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:11:21 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/26 15:38:44 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a, t_stack *b)
{
	t_stack	*aux;
	t_stack	*last;

	if (a)
	{
		aux = a;
		last = get_last(a);
		last->next = a->next;
		a->next = 0;
		if (!b)
			write(1, "sa\n", 3);
	}
	if (b)
	{
		aux = get_last(b);
		aux->next = b->next;
		b->next = 0;
		if (!a)
			write(1, "sb\n", 3);
	}
	if (a && b)
		write(1, "ss\n", 3);
}
