/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:00:00 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/25 21:33:44 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack(t_stack **a, char **argv, size_t len)
{
	t_stack	*aux;

	aux = 0;
	(*a) = ft_calloc(sizeof(t_stack), len);
	if (!(*a))
		ft_error();
	while (len--)
	{
		(*a)[len].next = aux;
		(*a)[len].nb = ft_atoi(argv[len]);
		aux = &(*a)[len];
	}
}
