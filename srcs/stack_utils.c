/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/17 00:54:33 by telufulu         ###   ########.fr       */
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
		i = 1;
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
