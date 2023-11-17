/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/17 01:13:27 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = 0;
	if (argc > 1)
	{
		set_stack(&a, argv + 1);
		check_stack(a, 0);
		if (argc == 2)
			return (0);
		else if (argc <= 4)
			small_sort(&a);
		else if (argc <= 11)
			medium_sort(&a, 10);
		check_stack(a, 0);
	}
	else
		ft_error();
	return (0);
}
