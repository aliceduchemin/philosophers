/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:37:28 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 20:06:11 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct	s_philos
{
	int			id;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
	int			number_of_time_each_philosophers_must_eat;
	long		last_meal;
	pthread_t	thread;
}				t_philos;

typedef struct	s_global
{
	t_philos	*philos;
	long		starting_time;
	int			number_of_philosophers;
	sem_t		*sem;
	sem_t		*limit;
	int			state;
}				t_global;

t_global		g_global;

# define DEAD 0
# define ALIVE 1

int				ft_parsing(int ac, char **av);
int				ft_number_of_args(int ac);
int				ft_value_of_args(int ac, char **av);

long			ft_get_time(void);

int				ft_init(int ac, char **av);
int				ft_create_global(char **av);
void			ft_create_philo(int ac, char **av);
void			ft_fill_starting_time(t_philos *philo);
int				ft_launch_threads(void);
void			*ft_launch_party(void *input);

int				ft_party(t_philos *philo);
void			ft_eat(t_philos *philo);
void			ft_sleep(t_philos *philo);
void			ft_think(t_philos *philo);

void			ft_join_threads(int nb);
int				ft_destruct_global(void);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
#endif
