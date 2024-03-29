/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:07:30 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/15 18:08:43 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	ft_eat(t_philos *philo)
{
	long		now;

	sem_wait(g_global.limit);
	sem_wait(g_global.sem);
	if (g_global.state == ALIVE)
		printf("%ld %d has taken a fork\n", ft_get_time() - \
			g_global.t0, philo->id);
	sem_wait(g_global.sem);
	if (g_global.state == ALIVE)
		printf("%ld %d has taken a fork\n", ft_get_time() - \
			g_global.t0, philo->id);
	now = ft_get_time();
	philo->last_meal = now;
	if (g_global.state == ALIVE)
		printf("%ld %d is eating\n", now - g_global.t0, philo->id);
	ft_usleep(g_global.time_to_eat);
	sem_post(g_global.limit);
	sem_post(g_global.sem);
	sem_post(g_global.sem);
}

void	ft_party(t_philos *philo)
{
	if (g_global.number_of_philosophers == 1)
	{
		ft_usleep(g_global.time_to_die * 1.1);
		return ;
	}
	ft_eat(philo);
	if (g_global.state == ALIVE)
	{
		printf("%ld %d is sleeping\n", ft_get_time() - g_global.t0, philo->id);
		ft_usleep(g_global.time_to_sleep);
	}
	if (g_global.state == ALIVE)
		printf("%ld %d is thinking\n", ft_get_time() - g_global.t0, philo->id);
}
