/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/27 16:16:10 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rename_nbs(t_stack **a)
{
	int		i;
	t_stack	*num_chekd;
	t_stack	*aux;

	num_chekd = *a;
	while (num_chekd)
	{
		aux = (*a);
		i = 0;
		while (aux)
		{
			if (num_chekd->nb > aux->nb)
				i++;
			aux = aux->next;
		}
		num_chekd->pos = i;
		num_chekd = num_chekd->next;
	}
}

void	set_stack(t_stack **a, char **num)
{
	char	**aux;
	size_t	i;
	size_t	j;

	i = 0;
	while (num[i])
	{
		j = 0;
		aux = ft_split(num[i], ' ');
		if (!aux)
			ft_error();
		while (aux[j])
		{
			if (!ft_str_digit(aux[j]))
				ft_error();
			ft_lstadd_back(a, ft_lstnew(ft_atoi(aux[j])));
			j++;
		}
		ft_free_split(aux, j);
		i++;
	}
	check_dup(*a);
	rename_nbs(a);
}

int	is_order(t_stack *x)
{
	while (x && x->next)
	{
		if (x->pos != (x->next)->pos - 1)
			return (0);
		x = x->next;
	}
	return (1);
}
