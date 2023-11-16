/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:05:48 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/16 21:33:29 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int nb)
{
	t_stack	*res;

	res = ft_calloc(sizeof(t_stack), 1);
	if (!res)
		return (NULL);
	res->nb = nb;
	res->next = NULL;
	return (res);
}
