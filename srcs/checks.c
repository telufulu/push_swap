/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:44:36 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/17 00:16:56 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(t_stack *a, t_stack *b)
{
	int	flag;

	flag = 0;
	while (a)
	{
		if (!flag)
			flag += write(1, "a: ", 3);
		ft_putnbr_base(a->pos, "0123456789");
		write(1, " ", 1);
		a = a->next;
	}
	if (flag)
		write(1, "\n", 1);
	flag = 0;
	while (b)
	{
		if (!flag)
			flag += write(1, "b: ", 3);
		ft_putnbr_base(b->pos, "0123456789");
		write(1, " ", 1);
		b = b->next;
	}
	if (flag)
		write(1, "\n", 1);
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
