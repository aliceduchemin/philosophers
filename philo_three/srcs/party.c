/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:54:13 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/15 18:10:26 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_eat(t_philos *philo)
{
	long		now;

	sem_wait(g_global.limit);
	sem_wait(g_global.sem);
	ft_print(philo->id, "has taken a fork");
	sem_wait(g_global.sem);
	ft_print(philo->id, "has taken a fork");
	now = ft_get_time();
	philo->last_meal = now;
	ft_print(philo->id, "is eating");
	ft_usleep(g_global.time_to_eat);
	sem_post(g_global.limit);
	sem_post(g_global.sem);
	sem_post(g_global.sem);
}

void	ft_party(t_philos *philo)
{
	ft_eat(philo);
	ft_print(philo->id, "is sleeping");
	ft_usleep(g_global.time_to_sleep);
	ft_print(philo->id, "is thinking");
}
