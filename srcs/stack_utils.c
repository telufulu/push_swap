/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/16 19:01:17 by telufulu         ###   ########.fr       */
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
		ft_putnbr_base(a->nb, "0123456789");
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
		ft_putnbr_base(b->nb, "0123456789");
		write(1, " ", 1);
		b = b->next;
	}
	if (flag)
		write(1, "\n", 1);
}
