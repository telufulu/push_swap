/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/14 11:57:47 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc >= 2)
	{
		set_stack(&a, argv + 1, argc - 1);
		check_stack(a, 0);
		if (argc == 4)
			sort_three(&a);
		else if (argc <= 6)
			sort_five(&a, &b);
		else if (argc > 6)
			ft_mergesort(&a);
		if (!is_order(a))
		{
			check_stack(a, 0);
			ft_error(4);
		}
	}
	else
		ft_error(1);
	check_stack(a, 0);
	return (0);
}
