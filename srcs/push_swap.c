/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/25 21:33:41 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//borrar
static void	check_stack(t_stack *a)
{
	while (a)
	{
		printf("%i ", a->nb);
		a = a->next;
	}
}

//
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = 0;
	if (argc >= 2)
	{
		check_arg(argc, argv);
		set_stack(&a, argv + 1, argc - 1);
		check_dup(a);
		check_stack(a);
	}
	else
		ft_error();
	return (0);
}
