/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/08 01:59:19 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc >= 2)
	{
		set_stack(&a, argv + 1, argc - 1);
		if (argc == 4)
			ft_bubblesort_a(&a);
		else if (argc <= 6)
			sort_five(&a);
		else
			algorithm_big(&a);
	}
	else
		ft_error(1);
	return (0);
}
