/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:42:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:26:33 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		ft_thread_error(int i)
{
	printf("Thread %d's creation did not work\n", i);
	ft_join_threads(i);
	ft_destruct_global();
	return (1);
}

void	ft_join_threads(int nb)
{
	void	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (nb == 1)
		return ;
	while (i < nb)
	{
		pthread_join(g_global.philos[i].thread, &ptr);
		i++;
	}
}

int		ft_destruct_global(void)
{
	int	i;

	i = 0;
	while (i < g_global.number_of_philosophers)
	{
		pthread_mutex_destroy(&(g_global.philos[i].left_mutex));
		i++;
	}
	pthread_mutex_destroy(&(g_global.mutex));
	free(g_global.philos);
	return (0);
}
