/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:44 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/25 13:53:29 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **err)
{
	size_t	i;

	i = 0;
	write(1, "\x1b[31mError\n\x1b[0m", 15);
	if (err)
	{
		free(err);
		err = 0;
	}
	exit (EXIT_FAILURE);
}
