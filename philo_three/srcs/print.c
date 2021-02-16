/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:16:16 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/16 15:16:18 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_print(int philo, char *msg)
{
	char	to_print[30];
	char	s[10];

	ft_bzero(to_print, 30);
	ft_bzero(s, 10);
	ft_itoa(s, ft_get_time() - g_global.t0);
	ft_strcat(to_print, s);
	ft_strcat(to_print, " ");
	ft_bzero(s, 10);
	ft_itoa(s, philo);
	ft_strcat(to_print, s);
	ft_strcat(to_print, " ");
	ft_strcat(to_print, msg);
	ft_strcat(to_print, "\n");
	ft_putstr_fd(to_print, 1);
}
