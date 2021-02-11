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
		ret = ft_launch_party(&(g_global.philos[philo]));
		if (ret == 2)
			exit(2);
		else if (ret == 1)
			exit(1);
		exit(0);
	}
	return (0);
}

int		ft_launch_party(t_philos *philo)
{
	int		i;

	ft_fill_starting_time(philo);
	i = 0;
	if (philo->number_of_time_each_philosophers_must_eat == -1)
	{
		while (1)
		{
			if (ft_party(philo) == 1)
				return (1);
		}
	}
	else
	{
		while (i < philo->number_of_time_each_philosophers_must_eat)
		{
			if (ft_party(philo) == 1)
				return (1);
			i++;
		}
	}
	return (2);
}
