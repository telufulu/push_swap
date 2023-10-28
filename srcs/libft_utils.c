/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:33:24 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/28 05:24:02 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;
	size_t	len;

	len = count * size;
	aux = malloc(len);
	if (!aux)
		return (0);
	while (len--)
		aux[len] = 0;
	return (aux);
}

int	ft_atoi(const char *str)
{
	long int		res;
	int				neg;

	neg = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	if (res > INT_MAX)
		ft_error(1);
	return (res * neg);
}

size_t	ft_putnbr_base(int nb, char *base)
{
	unsigned int	nbr;
	unsigned int	bs;
	size_t			nb_chars;
	int				aux;

	nb_chars = 0;
	nbr = 0;
	bs = ft_strlen(base);
	if (nb < 0 && bs == 10)
	{
		nb_chars += write(1, "-", 1);
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr > bs - 1)
		nb_chars += ft_putnbr_base((nbr / bs), base);
	aux = (nbr % bs);
	nb_chars += write(1, &base[aux], 1);
	return (nb_chars);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
