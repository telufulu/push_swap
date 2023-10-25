/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:12:12 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/25 20:32:11 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*
 * BORRAR
 */
# include <stdio.h>

# define INT_MAX 2147483647
typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

// push_swap.c

// libft_utils.c
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

// stack_utils.c
void	set_stack(t_stack **a, char **argv, size_t len);

// error_utils.c
void	ft_error(void);
void	check_arg(int argc, char **argv);
void	check_dup(t_stack *a);
#endif
