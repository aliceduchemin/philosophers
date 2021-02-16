/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:57:57 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/15 18:08:11 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		ft_init(int ac, char **av)
{
	if (ft_create_global(ac, av) == 1)
		return (1);
	ft_create_philo();
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
	g_global.nb_of_meals = 0;
	sem_unlink("Sem");
	g_global.sem = sem_open("Sem", O_CREAT, 0644, \
		g_global.number_of_philosophers);
	sem_unlink("Limit");
	g_global.limit = sem_open("Limit", O_CREAT, 0644, \
		g_global.number_of_philosophers / 2);
	g_global.state = ALIVE;
	if (!(g_global.philos = malloc(sizeof(t_philos) * \
		g_global.number_of_philosophers)))
		return (1);
	g_global.t0 = ft_get_time();
	return (0);
}

void	ft_create_philo(void)
{
	int		i;

	i = 0;
	while (i < g_global.number_of_philosophers)
	{
		g_global.philos[i].id = i;
		g_global.philos[i].last_meal = 0;
		i++;
	}
}
