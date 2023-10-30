/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:57:58 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/30 09:58:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *a)
{
	t_stack	*mid;
	t_stack	*last;
	size_t	len;
	size_t	i;

	i = 0;
	len = stack_len(a);
	last = (get_penult(a))->next;
	mid = a;
	while (i++ < (len / 2))
		mid = mid->next;
	return ((a->nb + mid->nb + last->nb) / 3);
}
