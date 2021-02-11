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
	printf("%ld %d has taken a fork\n", ft_get_time() - \
		g_global.starting_time, philo->id);
	sem_wait(g_global.sem);
	printf("%ld %d has taken a fork\n", ft_get_time() - \
		g_global.starting_time, philo->id);
	if ((now = ft_get_time()) - philo->last_meal > philo->time_to_die)
	{
		printf("%ld %d died\n", ft_get_time() - \
			g_global.starting_time, philo->id);
		g_global.state = DEAD;
	}
	else
	{
		printf("%ld %d is eating\n", ft_get_time() - \
			g_global.starting_time, philo->id);
		usleep(philo->time_to_eat * 1000);
	}
	sem_post(g_global.limit);
	sem_post(g_global.sem);
	sem_post(g_global.sem);
	philo->last_meal = now;
}

void	ft_sleep(t_philos *philo)
{
	printf("%ld %d is sleeping\n", ft_get_time() - \
		g_global.starting_time, philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	ft_think(t_philos *philo)
{
	printf("%ld %d is thinking\n", ft_get_time() - \
		g_global.starting_time, philo->id);
}

int		ft_party(t_philos *philo)
{
	ft_eat(philo);
	if (g_global.state == DEAD)
		return (1);
	ft_sleep(philo);
	if (g_global.state == DEAD)
		return (1);
	ft_think(philo);
	return (0);
}
