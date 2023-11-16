/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:34:10 by telufulu          #+#    #+#             */
/*   Updated: 2023/08/12 14:17:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*aux;
	size_t	len;

	len = count * size;
	aux = malloc(len);
	if (!aux)
		return (0);
	ft_bzero(aux, len);
	return (aux);
}
