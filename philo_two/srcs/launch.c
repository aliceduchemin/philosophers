/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:06:41 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 20:07:02 by aduchemi         ###   ########.fr       */
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
		usleep(100);
		philo++;
	}
	return (0);
}

void	*ft_launch_party(void *input)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)input;
	ft_fill_starting_time(philo);
	i = 0;
	if (philo->number_of_time_each_philosophers_must_eat == -1)
	{
		while (1)
		{
			if (ft_party(philo) == 1)
				return (NULL);
		}
	}
	else
	{
		while (i < philo->number_of_time_each_philosophers_must_eat)
		{
			if (ft_party(philo) == 1)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
