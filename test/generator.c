/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:14:47 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/05 21:30:32 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	size_t			len;
	size_t			i;
	unsigned int	num;

	len = atoi(argv[1]);
	i = 0;
	if (argc == 2)
	{
		srand(time(NULL));
		while (i++ < len)
		{
			num = rand() % 1000000;
			if (i < len)
				printf("%d ", num);
			else if (i == len)
				printf("%d\n", num);
		}
	}
	return (0);
}
