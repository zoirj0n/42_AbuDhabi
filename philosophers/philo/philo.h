/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:57:04 by zosobiro          #+#    #+#             */
/*   Updated: 2023/02/04 15:50:34 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_to_eat;
	int					eat;
	int					*fork_status;
	int					*sig;
	int					count;
	int					died;
	long long			start_time;
	pthread_mutex_t		*fork;
	pthread_mutex_t		eating;
	pthread_mutex_t		count_eat;
	pthread_mutex_t		die;
	pthread_mutex_t		printig;
}				t_info;

typedef struct s_philo
{
	int			eat;
	int			id;
	long long	last_ate;
	int			lfork;
	int			rfork;
	pthread_t	philo_t;
	t_info		*info;
}				t_philo;

int			ft_isdigit(int number);
int			ft_atoi(char *str);
long long	get_time(void);
void		philo_pause(t_philo *philo, int time_pause);
void		print(t_philo *philo, int id, char *is_doing);
int			double_check(int ac, char **av);
void		philo_eat(t_philo *philo);
int			start(t_philo *philo);
void		info_init(t_philo *philo, t_info *info, int ac, char **av);
int			ft_check_died(t_philo *philo);
void		check_done_eat_and_die(t_philo *phil);

#endif