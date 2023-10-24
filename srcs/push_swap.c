/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/24 21:39:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	set_stacks(t_stack *a, t_stack *b)
{
	b->nb = 0;
	b->next = 0;
}

int	main(int argc, char argv)
{
	t_stack	a;
	t_stack	b;

	if (argc >= 2)
	{
		set_stacks(&a, &b);
	}
	else
		ft_error(1);
	return (0);
}
