/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:00:00 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/26 13:16:34 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(t_stack *a)
{
	while (a)
	{
		ft_putnbr_base(a->nb, "0123456789");
		write(1, " ", 1);
		a = a->next;
	}
	write(1, "\n", 1);
}

void	set_stack(t_stack **a, char **argv, size_t len)
{
	t_stack	*aux;

	aux = 0;
	check_arg(len, argv);
	(*a) = ft_calloc(sizeof(t_stack), len);
	if (!(*a))
		ft_error();
	while (len--)
	{
		(*a)[len].next = aux;
		(*a)[len].nb = ft_atoi(argv[len]);
		aux = &(*a)[len];
	}
	check_dup((*a));
}

t_stack	*get_last(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a);
}
