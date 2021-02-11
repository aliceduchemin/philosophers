/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:31:56 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 00:18:17 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		main(int ac, char **av)
{
	int			ret;

	if (ft_parsing(ac, av))
		return (1);
	if (ft_init(ac, av))
		return (1);
	ret = ft_launch_threads();
	ft_join_threads(g_global.number_of_philosophers);
	ft_destruct_global();
	if (ret == 1)
		return (1);
	return (0);
}
