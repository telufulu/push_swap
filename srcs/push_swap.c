/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/21 21:08:53 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc > 1)
	{
		set_stack(&a, argv + 1);
		check_stack(a, 0);
		if (argc == 2)
			return (0);
		else if ((argc - 1) <= 3)
			small_sort(&a);
		else if ((argc - 1) < 10)
			final_sort(&a, &b);
		else if ((argc - 1) >= 10)
			big_sort(&a);
		if (!is_order(a))
			ft_error();
	}
	else
		ft_error();
	return (0);
}
