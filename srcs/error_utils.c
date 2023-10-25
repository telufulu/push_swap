/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:44 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/25 20:32:32 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "\x1b[31mError\n\x1b[0m", 15);
	exit(EXIT_FAILURE);
}

void	check_arg(int argc, char **argv)
{
	while (--argc > 1)
	{
		if (*argv[argc] <= '0' || *argv[argc] >= '9')
			ft_error();
	}
}

void	check_dup(t_stack *a)
{
	int		x;
	t_stack	*i;
	t_stack *aux;

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
