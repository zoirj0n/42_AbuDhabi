/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:57:05 by zosobiro          #+#    #+#             */
/*   Updated: 2023/01/21 11:57:06 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int left_hand_fork, int right_hand_fork, int id)
{
	pthread_mutex_lock(&(philo->info->count_eat));
	philo->ate++;
	if (philo->ate == philo->info->must_to_eat)
		philo->info->count++;
	pthread_mutex_unlock(&(philo->info->count_eat));
	pthread_mutex_lock(&(philo->info->fork[left_hand_fork]));
	philo->info->fork_status[left_hand_fork] = 1;
	philo->info->sig[left_hand_fork] = philo->id;
	print(philo, id, "has taken a fork");
	pthread_mutex_unlock(&(philo->info->fork[left_hand_fork]));
	pthread_mutex_lock(&(philo->info->fork[right_hand_fork]));
	philo->info->fork_status[right_hand_fork] = 1;
	philo->info->sig[right_hand_fork] = philo->id;
	print(philo, id, "has taken a fork");
	pthread_mutex_unlock(&(philo->info->fork[right_hand_fork]));
}

int	cheack_fork_status(t_philo *philo)
{
	int	right_hand_fork;
	int	left_hand_fork;
	int	rsig;
	int	lsig;

	if (philo->info->num_philo == 1)
		return (0);
	pthread_mutex_lock(&(philo->info->fork[philo->right_hand_fork]));
	right_hand_fork = philo->info->fork_status[philo->right_hand_fork];
	rsig = philo->info->sig[philo->right_hand_fork];
	pthread_mutex_unlock(&(philo->info->fork[philo->right_hand_fork]));
	pthread_mutex_lock(&(philo->info->fork[philo->left_hand_fork]));
	left_hand_fork = philo->info->fork_status[philo->left_hand_fork];
	lsig = philo->info->sig[philo->left_hand_fork];
	pthread_mutex_unlock(&(philo->info->fork[philo->left_hand_fork]));
	if (left_hand_fork == 0 && right_hand_fork == 0 && lsig != philo->id && rsig != philo->id)
	{
		take_fork(philo, philo->left_hand_fork, philo->right_hand_fork, philo->id);
		return (1);
	}
	return (0);
}

void	to_put_down_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->fork[philo->left_hand_fork]));
	philo->info->fork_status[philo->left_hand_fork] = 0;
	pthread_mutex_unlock(&(philo->info->fork[philo->left_hand_fork]));
	pthread_mutex_lock(&(philo->info->fork[philo->right_hand_fork]));
	philo->info->fork_status[philo->right_hand_fork] = 0;
	pthread_mutex_unlock(&(philo->info->fork[philo->right_hand_fork]));
}

void	philo_eat(t_philo *philo)
{
	while (!ft_check_died(philo))
	{
		usleep(100);
		if (cheack_fork_status(philo))
			break ;
	}
	print(philo, philo->id, "is eating");
	philo_pause(philo, philo->info->time_to_eat);
	pthread_mutex_lock(&(philo->info->eating));
	philo->last_ate = get_time();
	pthread_mutex_unlock(&(philo->info->eating));
	to_put_down_fork(philo);
}
