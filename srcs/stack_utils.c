/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/16 22:57:15 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

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
