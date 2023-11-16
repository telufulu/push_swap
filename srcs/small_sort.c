/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:19:49 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/17 00:37:34 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
{
	t_stack	*two;
	t_stack	*three;

	while (!is_order(*a))
	{
		two = (*a)->next;
		three = two->next;
		if ((*a)->nb > two->nb && (*a)->nb > three->nb)
			rotate(a, 0);
		else if (((*a)->nb > three->nb && two->nb < three->nb) || 
			((*a)->nb > three->nb && two->nb > three->nb))
			rev_rotate(a, 0);
		else if ((*a)->nb > two->nb || 
			((*a)->nb < two->nb && (*a)->nb < three->nb))
			swap(a, 0);
	}
}
