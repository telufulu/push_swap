/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/26 17:51:26 by telufulu         ###   ########.fr       */
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
		check_stack(a);
		swap(&a, 0);
		check_stack(a);
		b = a;
		swap(0, &b);
		check_stack(b);
	}
	else
		ft_error();
	return (0);
}
