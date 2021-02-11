/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:41:43 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:30:41 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

long	ft_get_time(void)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000;
	ms += tp.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(int wait, int philo, int i)
{
	long	begin;
	long	tmp;
(void)philo;
(void)i;
	begin = ft_get_time();
	tmp = begin + (long)wait;
	while (ft_get_time() < tmp)
	{
		usleep(wait);
	}
//	printf("  %d %d start sleep %ld till %ld yet end usleep=%ld\n", philo, i, begin - g_global.t0, tmp - g_global.t0, ft_get_time() - g_global.t0);
}