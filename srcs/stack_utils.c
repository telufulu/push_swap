/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:00:00 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:26 by telufulu         ###   ########.fr       */
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

void	set_stack(t_stack **a, char **argv, size_t len)
{
	t_stack	*aux;

	aux = 0;
	check_arg(len, argv);
	(*a) = ft_calloc(sizeof(t_stack), len);
	if (!(*a))
		ft_error(1);
	while (len--)
	{
		(*a)[len].next = aux;
		(*a)[len].nb = ft_atoi(argv[len]);
		aux = &(*a)[len];
	}
	check_dup((*a));
	convert_numbers(*a);
}

t_stack	*get_penult(t_stack *x)
{
	while ((x->next)->next)
		x = x->next;
	return (x);
}

int	is_order(t_stack *a)
{
	int	aux;

	while (a && a->next)
	{
		aux = a->nb;
		a = a->next;
		if (aux > a->nb)
			return (0);
	}
	return (1);
}

int	is_rev_order(t_stack *a)
{
	int	aux;

	while (a && a->next)
	{
		aux = a->nb;
		a = a->next;
		if (aux < a->nb)
			return (0);
	}
	return (1);
}

size_t	stack_len(t_stack *a)
{
	size_t	i;

	i = 0;
	while (a && ++i)
		a = a->next;
	return (i);
}
