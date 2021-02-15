/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liveliness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:06:37 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/12 18:06:38 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		ft_liveliness(void)
{
	int		philo;
	int		status;

	status = 0;
	philo = 0;
/*	while (g_global.state == ALIVE)
	{
		usleep(500);
	}*/
//	while (philo < g_global.number_of_philosophers)
	while (g_global.state == ALIVE)
	{
		waitpid(g_global.philos[philo].pid, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			g_global.state = DEAD;
			printf("%ld wexittatus=1\n", ft_get_time() - g_global.t0);
			return (1);
		}
		else if (WEXITSTATUS(status) == 2)
		{
			g_global.state = FINISHED;
			return (2);
		}
		//philo++;
		philo = (philo + 1) % g_global.number_of_philosophers;
	}
	return (0);
}