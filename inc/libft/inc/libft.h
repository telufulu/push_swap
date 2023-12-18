/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:31:25 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/18 16:43:01 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define UINT_MAX 4294967295

// C Standard
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// No Standard
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_free(char **res, int i);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// Lists
typedef struct s_stack
{
	int				nb;
	unsigned int	pos;
	struct s_stack	*next;
}				t_stack;

t_stack		*ft_lstnew(int nb);
size_t		ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstpen(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);

// Additional functions
char		**ft_free_split(char **res, int i);
void		ft_error(void);
size_t		ft_putnbr_base(int nb, char *base);
int			ft_str_digit(char *s);
int			ft_isodd(int i);
#endif
