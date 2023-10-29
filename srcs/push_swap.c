/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:13:29 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/29 14:59:24 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc >= 2)
	{
		set_stack(&a, argv + 1, argc - 1);
		quicksort(&a);
		free(a);
	}
	else
		ft_error(1);
	return (0);
}
