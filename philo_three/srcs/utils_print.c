/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:23:48 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/16 15:24:17 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_strcat(char *dst, char *src)
{
	unsigned int	length_dst;
	unsigned int	i;

	length_dst = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[length_dst] = src[i];
		length_dst++;
		i++;
	}
	dst[length_dst] = 0;
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	ft_convert(int n, char *s, int *i)
{
	if (n > 9)
		ft_convert(n / 10, s, i);
	s[*i] = n % 10 + 48;
	*i = *i + 1;
	s[*i] = 0;
}

void	ft_itoa(char *s, int n)
{
	int		i;

	if (n == -2147483648)
	{
		s[0] = '-';
		s[1] = '2';
		n = 147483648;
		i = 2;
	}
	else if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		i = 1;
	}
	else
		i = 0;
	ft_convert(n, s, &i);
}
