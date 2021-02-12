/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:14:19 by aduchemi          #+#    #+#             */
/*   Updated: 2021/02/09 23:27:58 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define ALIVE 1
# define DEAD 0
# define EATING 2

typedef struct		s_philos
{
	int				id;
	long			last_meal;
	pthread_t		thread;
	int				state;
	int				*left_state;
	int				*right_state;
	pthread_mutex_t	left_mutex;
	pthread_mutex_t	*right_mutex;
}					t_philos;

typedef struct		s_global
{
	t_philos		*philos;
	pthread_mutex_t	mutex;
	long			t0;
	int				number_of_philosophers;
	int				state;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_time_each_philosophers_must_eat;
}					t_global;

t_global	g_global;

int					ft_parsing(int ac, char **av);
int					ft_number_of_args(int ac);
int					ft_value_of_args(int ac, char **av);
long				ft_get_time(void);
void				ft_usleep(int wait);

void				ft_monitor(void);

int					ft_init(int ac, char **av);
int					ft_create_global(int ac, char **av);
void				ft_create_philos(void);
void				ft_create_right_fork(void);
int					ft_launch_threads(void);
void				*ft_launch_party(void *input);

void				ft_party(t_philos *philo);
void				ft_eat(t_philos *philo);
void				ft_forks(t_philos *philo);

void				ft_join_threads(int nb);
void				ft_destruct_global(void);
int					ft_thread_error(int i);

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);

#endif
