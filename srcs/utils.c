/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:33:24 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/24 21:39:45 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int err)
{
	write(1, "\x1b[31merror: \x1b[0m", 16);
	if (err == 1)
		write(1, "wrong number of arguments\n", 26);
	exit (EXIT_FAILURE);
}
