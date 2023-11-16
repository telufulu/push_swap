/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:37:26 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/16 19:25:15 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "\x1b[31mError\x1b[0m\n", 15);
	exit(EXIT_FAILURE);
}

void	check_dup(t_stack *a)
{
	int		x;
	t_stack	*i;
	t_stack	*aux;

	aux = a;
	while (aux)
	{
		x = aux->nb;
		i = aux->next;
		while (i)
		{
			if (i->nb == x)
			{
				free(a);
				ft_error();
			}
			i = i->next;
		}
		aux = aux->next;
	}
}

int	is_order(t_stack *x)
{
	int	aux;

	while (x && x->next)
	{
		aux = x->nb;
		x = x->next;
		if (aux > x->nb)
			return (0);
	}
	return (1);
}

int	is_rev_order(t_stack *x)
{
	int	aux;

	while (x && x->next)
	{
		aux = x->nb;
		x = x->next;
		if (aux < x->nb)
			return (0);
	}
	return (1);
}
