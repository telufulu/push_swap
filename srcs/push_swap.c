/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/27 21:15:28 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = 0;
	if (argc >= 2)
	{
		set_stack(&a, argv + 1, argc - 1);
		set_stack(&b, argv + 1, argc - 1);
		write(1, "a: ", 3);
		check_stack(a);
		write(1, "b: ", 3);
		check_stack(b);
		swap(0, &b);
		write(1, "a: ", 3);
		check_stack(a);
		write(1, "b: ", 3);
		check_stack(b);
	}
	else
		ft_error();
	return (0);
}
