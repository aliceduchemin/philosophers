/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:05:22 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:56:22 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		ft_destruct_global(void)
{
	free(g_global.philos);
	sem_close(g_global.sem);
	sem_close(g_global.limit);
	return (0);
}

void	ft_join_threads(int nb)
{
	void	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	while (i < nb)
	{
		pthread_join(g_global.philos[i].thread, &ptr);
		i++;
	}
}
