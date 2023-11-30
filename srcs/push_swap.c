/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/30 19:56:56 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	size_t	size;

	a = 0;
	b = 0;
	if (argc > 1)
	{
		set_stack(&a, argv + 1);
		size = ft_lstsize(a);
		//check_stack(a, 0);
		if (size == 1)
			return (0);
		else if (size <= 3)
			small_sort(&a, &b);
		else if (size <= 5)
			medium_sort(&a, &b);
		else if (size > 5)
			big_sort(&a, &b);
		check_stack(a, 0);
		if (!is_order(a))
			ft_error();
	}
	else
		ft_error();
	return (0);
}
