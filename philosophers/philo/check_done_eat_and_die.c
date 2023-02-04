/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_done_eat_and_die.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:56:53 by zosobiro          #+#    #+#             */
/*   Updated: 2023/02/04 15:51:39 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	philo->info->died = 1;
	pthread_mutex_unlock(&(philo->info->die));
}

void	to_check_eating_is_fisnished(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	philo->info->eat = 1;
	pthread_mutex_unlock(&(philo->info->die));
}

int	ft_check_died(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	if (philo->info->died)
	{
		pthread_mutex_unlock(&(philo->info->die));
		return (1);
	}
	pthread_mutex_unlock(&(philo->info->die));
	return (0);
}

int	to_check_death(t_philo *philo)
{
	int			i;
	long long	time;

	pthread_mutex_lock(&philo->info->count_eat);
	if (philo->info->must_to_eat > 0 && \
		philo->info->count >= philo->info->num_philo)
		to_check_eating_is_fisnished(philo);
	pthread_mutex_unlock(&philo->info->count_eat);
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_lock(&(philo->info->eating));
		time = philo[i].last_ate;
		pthread_mutex_unlock(&(philo->info->eating));
		if (get_time() - time >= philo->info->time_to_die)
		{
			print(philo, i, "died");
			die(philo);
		}
		if (ft_check_died(philo))
			return (1);
		i++;
	}
	return (0);
}

void	check_done_eat_and_die(t_philo *phil)
{
	while (!phil->info->eat)
	{
		usleep(200);
		if (to_check_death(phil) || phil->info->eat)
			break ;
	}
}
