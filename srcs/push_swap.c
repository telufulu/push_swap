/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/18 13:55:33 by telufulu         ###   ########.fr       */
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
		if (size == 1)
			return (0);
		else if (!is_order(a) && size <= 3)
			small_sort(&a, &b);
		else if (!is_order(a) && size <= 5)
			medium_sort(&a, &b);
		else if (!is_order(a) && size > 5)
			big_sort(&a, &b, size - 1);
	}
	return (0);
}
