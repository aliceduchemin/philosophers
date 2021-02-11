/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:07:14 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/10 13:51:43 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		ft_parsing(int ac, char **av)
{
	if (ft_number_of_args(ac) == 1)
		return (1);
	if (ft_value_of_args(ac, av) == 1)
		return (1);
	return (0);
}

int		ft_number_of_args(int ac)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Number of arguments is incorrect\n", 2);
		return (1);
	}
	return (0);
}

int		ft_value_of_args(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				ft_putstr_fd("Arguments must be positive numbers\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_strcmp(av[1], "0") == 0)
	{
		ft_putstr_fd("There needs to be at least 1 philosopher \
to throw a party\n", 2);
		return (1);
	}
	return (0);
}
