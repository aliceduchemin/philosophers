/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:54:13 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:54:53 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_eat(t_philos *philo)
{
	long		now;

	sem_wait(g_global.limit);
	sem_wait(g_global.sem);
	printf("%ld %d has taken a fork\n", ft_get_time() - g_global.t0, philo->id);
	sem_wait(g_global.sem);
	printf("%ld %d has taken a fork\n", ft_get_time() - g_global.t0, philo->id);
	now = ft_get_time();
	philo->last_meal = now;
	printf("%ld %d is eating\n", ft_get_time() - g_global.t0, philo->id);
	ft_usleep(g_global.time_to_eat);
	sem_post(g_global.limit);
	sem_post(g_global.sem);
	sem_post(g_global.sem);
}

void	ft_party(t_philos *philo)
{
	ft_eat(philo);
	printf("%ld %d is sleeping\n", ft_get_time() - \
		g_global.t0, philo->id);
	ft_usleep(g_global.time_to_sleep);
	printf("%ld %d is thinking\n", ft_get_time() - \
		g_global.t0, philo->id);
}
