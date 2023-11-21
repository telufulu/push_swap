/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/21 21:10:00 by telufulu         ###   ########.fr       */
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
	size_t	len;
	size_t	i;

	i = 1;
	len = ft_lstsize(x);
	while (i <= len)
	{
		if (x->pos != i)
			return (0);
		x = x->next;
		i++;
	}
	return (1);
}

int	is_rev_order(t_stack *x)
{
	size_t	len;

	len = ft_lstsize(x);
	while (len)
	{
		if (!(x->pos == len))
			return (0);
		x = x->next;
		len--;
	}
	return (1);
}
