/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:06:41 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/16 16:24:27 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		ft_launch_threads(void)
{
	int		philo;

	philo = 0;
	while (philo < g_global.number_of_philosophers)
	{
		if (pthread_create(&(g_global.philos[philo].thread), NULL, \
		ft_launch_party, (void *)(&g_global.philos[philo])))
		{
			printf("Thread %d's creation did not work\n", philo);
			ft_join_threads(philo);
			ft_destruct_global();
			return (1);
		}
		philo++;
	}
	ft_monitor();
	return (0);
}

int		ft_monitor(void)
{
	int		philo;
	long	now;
	int		tmp;

	tmp = g_global.number_of_time_each_philosophers_must_eat;
	philo = 0;
	while (g_global.state == ALIVE && (tmp == -1 || g_global.nb_of_meals < tmp))
	{
		if (philo == 0)
			usleep(500);
		if (g_global.philos[philo].last_meal != 0 && (now = ft_get_time()) - \
			g_global.philos[philo].last_meal > g_global.time_to_die)
		{
			g_global.state = DEAD;
			printf("%ld %d died\n", ft_get_time() - g_global.t0, philo);
			return (1);
		}
		philo = (philo + 1) % g_global.number_of_philosophers;
	}
	return (0);
}

void	*ft_launch_party(void *input)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)input;
	if (philo->id % 2 == 0)
		usleep(g_global.time_to_eat * 0.9);
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
		g_global.nb_of_meals++;
	}
	return (NULL);
}
