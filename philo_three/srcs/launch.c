/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:53:03 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/15 18:11:01 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_launch(void)
{
	int		philo;

	philo = 0;
	while (philo < g_global.number_of_philosophers)
	{
		g_global.philos[philo].pid = fork();
		if (g_global.philos[philo].pid == 0)
		{
			if (pthread_create(&(g_global.philos[philo].monitor_thread), NULL, \
			ft_monitor, (void *)(&(g_global.philos[philo]))))
			{
				ft_putstr_fd("Thread creation did not work\n", 2);
				ft_destruct_global();
				exit(1);
			}
			pthread_detach(g_global.philos[philo].monitor_thread);
			ft_launch_party(&(g_global.philos[philo]));
			exit(0);
		}
		philo++;
	}
}

void	*ft_monitor(void *input)
{
	t_philos	*philo;
	long		now;
	int			i;

	philo = (t_philos *)input;
	i = 0;
	while (1)
	{
		if (g_global.philos[i].last_meal != 0 && (now = ft_get_time()) - \
			g_global.philos[i].last_meal > g_global.time_to_die)
		{
			ft_print(philo->id, "died");
			sem_post(g_global.alive);
		}
		usleep(500);
		i = (i + 1) % g_global.number_of_philosophers;
	}
	return (NULL);
}

void	ft_launch_party(t_philos *philo)
{
	int		i;

	philo->last_meal = ft_get_time();
	i = 0;
	if (g_global.number_of_time_each_philosophers_must_eat == -1)
	{
		while (1)
			ft_party(philo);
	}
	else
	{
		while (i < g_global.number_of_time_each_philosophers_must_eat)
		{
			ft_party(philo);
			i++;
		}
		sem_post(g_global.alive);
	}
}
