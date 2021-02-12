/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:53:03 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:53:29 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		ft_launch_threads(void)
{
	int		philo;

	philo = 0;
	while (philo < g_global.number_of_philosophers)
	{
		ft_fork_philos(philo);
		philo++;
	}
	if (ft_liveliness() == 1)
		ft_kill_processes();
	return (0);
}

int		ft_fork_philos(int philo)
{
	int		ret;
	g_global.philos[philo].pid = fork();
	if (g_global.philos[philo].pid == 0)
	{
		if (pthread_create(&(g_global.philos[philo].monitor_thread), NULL, \
		ft_monitor, (void *)(&(g_global.philos[philo]))))
		{
			printf("Thread %d's creation did not work\n", philo);
			ft_destruct_global();
			exit (1);
		}
		ret = ft_launch_party(&(g_global.philos[philo]));
		if (ret == 1)
			exit (1);
		else if (ret == 2)
			exit (2);
	}
	return (0);
}

void	*ft_monitor(void *input)
{
	t_philos	*philo;
	long	now;

	philo = (t_philos *)input;
	while (g_global.state == ALIVE)
	{
	//	ft_usleep(g_global.time_to_eat);
		if (philo->last_meal != 0 && (now = ft_get_time()) - \
			philo->last_meal > g_global.time_to_die)
		{
			g_global.state = DEAD;
			printf("%ld %d died, last meal %ld ago\n", ft_get_time() - g_global.t0, philo->id, now - philo->last_meal);
			break ;
		}
	}
	return (NULL);
}

int		ft_launch_party(t_philos *philo)
{
	int		i;

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
		return (2);
	}
	return (1);
}