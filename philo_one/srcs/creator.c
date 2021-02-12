/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:18:32 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/11 17:53:18 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		ft_init(int ac, char **av)
{
	if (ft_create_global(ac, av) == 1)
		return (1);
	ft_create_philos();
	ft_create_right_fork();
	return (0);
}

int		ft_create_global(int ac, char **av)
{
	g_global.number_of_philosophers = ft_atoi(av[1]);
	g_global.time_to_die = ft_atoi(av[2]);
	g_global.time_to_eat = ft_atoi(av[3]);
	g_global.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		g_global.number_of_time_each_philosophers_must_eat = \
			ft_atoi(av[5]);
	else
		g_global.number_of_time_each_philosophers_must_eat = -1;
	pthread_mutex_init(&(g_global.mutex), NULL);
	g_global.state = ALIVE;
	if (!(g_global.philos = malloc(sizeof(t_philos) * \
		g_global.number_of_philosophers)))
		return (1);
	g_global.t0 = ft_get_time();
	return (0);
}

void	ft_create_philos(void)
{
	int	i;

	i = 0;
	while (i < g_global.number_of_philosophers)
	{
		g_global.philos[i].id = i;
		g_global.philos[i].state = ALIVE;
		g_global.philos[i].last_meal = 0;
		pthread_mutex_init(&(g_global.philos[i].left_mutex), NULL);
		i++;
	}
}

void	ft_create_right_fork(void)
{
	int	i;
	int	next;
	int	previous;

	i = 0;
	while (i < g_global.number_of_philosophers)
	{
		next = (i + 1) % g_global.number_of_philosophers;
		previous = (i + g_global.number_of_philosophers - 1) % \
			g_global.number_of_philosophers;
		g_global.philos[i].right_mutex = &(g_global.philos[next].left_mutex);
		g_global.philos[i].right_state = &(g_global.philos[next].state);
		g_global.philos[i].left_state = &(g_global.philos[previous].state);
		i++;
	}
}
