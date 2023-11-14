/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:44 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/14 11:26:54 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int flag)
{
	write(1, "\x1b[31mError\x1b[0m", 14);
	if (flag == 1)
		write(1, " 1\n", 3);
	else if (flag == 2)
		write(1, " 2\n", 3);
	else if (flag == 3) // Dup numbers
		write(1, " 3\n", 3);
	else if (flag == 4) //Is not order
		write(1, " 4\n", 3);
	exit(EXIT_FAILURE);
}

void	check_arg(int argc, char **argv)
{
	while (--argc > 1)
	{
		if (*argv[argc] < '0' || *argv[argc] > '9')
			ft_error(2);
	}
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
				ft_error(3);
			}
			i = i->next;
		}
		aux = aux->next;
	}
}
