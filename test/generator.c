/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:14:39 by telufulu          #+#    #+#             */
/*   Updated: 2023/11/14 18:51:40 by telufulu         ###   ########.fr       */
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
			num = rand() % 10000;
			if (i < len)
				printf("%d ", num);
			else if (i == len)
				printf("%d\n", num);
		}
	}
	return (0);
}
