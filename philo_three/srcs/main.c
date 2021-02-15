/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:31:56 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:53:42 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		main(int ac, char **av)
{
	if (ft_parsing(ac, av))
		return (1);
	if (ft_init(ac, av))
		return (1);
	ft_launch();
	ft_liveliness();
	ft_destruct_processes();
	ft_destruct_global();
	return (0);
}