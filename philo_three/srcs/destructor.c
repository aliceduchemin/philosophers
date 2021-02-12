/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:52:06 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:52:28 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		ft_destruct_global(void)
{
	int		philo;

	philo = 0;
	while (philo < g_global.number_of_philosophers)
	{
		kill(g_global.philos[philo].pid, SIGKILL);
		philo++;
	}
	free(g_global.philos);
	sem_close(g_global.sem);
	sem_close(g_global.limit);
	return (0);
}