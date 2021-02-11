/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:55:05 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:55:07 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

long	ft_get_time(void)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000;
	ms += tp.tv_usec / 1000;
	return (ms);
}

void	ft_fill_starting_time(t_philos *philo)
{
	g_global.starting_time = ft_get_time();
	philo->last_meal = g_global.starting_time;
}
