/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:43:39 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:30:04 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	ft_eat(t_philos *philo)
{
	long		now;

	while (g_global.state == ALIVE && *(philo->right_state) != ALIVE && *(philo->left_state) != ALIVE)
	{
		usleep(1000);
	}
	pthread_mutex_lock(philo->p_to_global_mutex);
	philo->state = EATING;
	if (g_global.state == ALIVE)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->right_mutex);
		else
			pthread_mutex_lock(&(philo->left_mutex));
		printf("%ld %d has taken left fork\n", ft_get_time() - \
			g_global.t0, philo->id);
		if (philo->id % 2 == 0)
			pthread_mutex_lock(&(philo->left_mutex));
		else
			pthread_mutex_lock(philo->right_mutex);
		pthread_mutex_unlock(philo->p_to_global_mutex);
		
		printf("%ld %d has taken right fork\n", ft_get_time() - \
			g_global.t0, philo->id);
		now = ft_get_time();
		philo->last_meal = now;
		printf("%ld %d is eating\n", now - \
			g_global.t0, philo->id);
		ft_usleep(philo->time_to_eat, philo->id, 1);
		pthread_mutex_unlock(&(philo->left_mutex));
		pthread_mutex_unlock(philo->right_mutex);
	}
	else
		pthread_mutex_unlock(philo->p_to_global_mutex);
	philo->state = ALIVE;
}

void	ft_party(t_philos *philo)
{
	ft_eat(philo);
	if (g_global.state != DEAD)
	{
		printf("%ld %d is sleeping\n", ft_get_time() - \
			g_global.t0, philo->id);
		ft_usleep(philo->time_to_sleep, philo->id, 2);
	}
	if (g_global.state != DEAD)
	{
		printf("%ld %d is thinking\n", ft_get_time() - \
			g_global.t0, philo->id);
	}
}