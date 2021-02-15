/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:40:33 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/11 17:58:40 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		ft_launch_threads(void)
{
	int		philo;

	philo = 0;
	while (philo < g_global.number_of_philosophers)
	{
		if (pthread_create(&(g_global.philos[philo].thread), NULL, \
		ft_launch_party, (void *)(&g_global.philos[philo])))
			return (ft_thread_error(philo));
		philo++;
	}
	ft_monitor();
	return (0);
}

void	ft_monitor(void)
{
	int		philo;
	long	now;

	philo = 0;
	while (g_global.state == ALIVE)
	{
		if (philo == 0)
			usleep(500);
		if (g_global.philos[philo].last_meal != 0 && (now = ft_get_time()) - \
			g_global.philos[philo].last_meal > g_global.time_to_die)
		{
			g_global.state = DEAD;
			printf("%ld %d died\n", ft_get_time() - g_global.t0, philo);
			break ;
		}
		philo = (philo + 1) % g_global.number_of_philosophers;
	}
}

void	*ft_launch_party(void *input)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)input;
	if (philo->id % 2 == 0)
		usleep(g_global.time_to_eat * 0.9);
	philo->state = ALIVE;
	philo->last_meal = ft_get_time();
	i = 0;
	if (g_global.number_of_time_each_philosophers_must_eat == -1)
	{
		while (g_global.state == ALIVE)
			ft_party(philo);
	}
	else
	{
		while (i < g_global.number_of_time_each_philosophers_must_eat \
			&& g_global.state == ALIVE)
		{
			ft_party(philo);
			i++;
		}
		g_global.state = DEAD;
	}
	return (NULL);
}
