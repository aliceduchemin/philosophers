/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:43:39 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/15 18:07:08 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	ft_eat(t_philos *philo)
{
	long		now;

	while (g_global.state == ALIVE && *(philo->right_state) != ALIVE && \
		*(philo->left_state) != ALIVE)
		usleep(1000);
	pthread_mutex_lock(&(g_global.mutex));
	philo->state = EATING;
	if (g_global.state == ALIVE)
	{
		ft_forks(philo);
		pthread_mutex_unlock(&(g_global.mutex));
		now = ft_get_time();
		philo->last_meal = now;
		if (g_global.state == ALIVE)
			printf("%ld %d is eating\n", now - g_global.t0, philo->id);
		ft_usleep(g_global.time_to_eat);
		pthread_mutex_unlock(&(philo->left_mutex));
		pthread_mutex_unlock(philo->right_mutex);
	}
	else
		pthread_mutex_unlock(&(g_global.mutex));
	philo->state = ALIVE;
}

void	ft_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_mutex);
	else
		pthread_mutex_lock(&(philo->left_mutex));
	if (g_global.state == ALIVE)
		printf("%ld %d has taken a fork\n", ft_get_time() - \
			g_global.t0, philo->id);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&(philo->left_mutex));
	else
		pthread_mutex_lock(philo->right_mutex);
	if (g_global.state == ALIVE)
		printf("%ld %d has taken a fork\n", ft_get_time() - \
			g_global.t0, philo->id);
}

void	ft_party(t_philos *philo)
{
	if (g_global.number_of_philosophers == 1)
		return ;
	ft_eat(philo);
	if (g_global.state == ALIVE)
	{
		printf("%ld %d is sleeping\n", ft_get_time() - \
			g_global.t0, philo->id);
		ft_usleep(g_global.time_to_sleep);
	}
	if (g_global.state == ALIVE)
		printf("%ld %d is thinking\n", ft_get_time() - g_global.t0, philo->id);
}
