/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endoflife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:52:39 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:52:40 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		ft_liveliness(void)
{
	int		philo;
	int		status;

	status = 0;
	philo = 0;
	printf("liveliness\n");
	while (philo < g_global.number_of_philosophers)
	{
		waitpid(g_global.philos[philo].pid, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			g_global.state = DEAD;
			return (1);
		}
		else if (WEXITSTATUS(status) == 2)
			g_global.state = FINISHED;
		philo++;
	}
	return (0);
}

int		ft_kill_processes(void)
{
	int		philo;
	printf("kill processes\n");
	philo = 0;
	while (philo < g_global.number_of_philosophers)
	{
		kill(g_global.philos[philo].pid, SIGTERM);
		philo++;
	}
	return (0);
}
