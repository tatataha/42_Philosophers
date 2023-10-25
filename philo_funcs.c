/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:18:33 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 16:12:00 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_think(t_philo *philo)
{
	messager("is thinking.", philo, philo->id);
}

void	philo_zzz(t_philo *philo)
{
	messager("is sleeping.", philo, philo->id);
	my_usleep(philo->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	messager("has taken a fork.", philo, philo->id);
	if (philo->philo_num == 1)
	{
		my_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	messager("has taken a fork", philo, philo->id);
	philo->eating = 1;
	messager("is eating.", philo, philo->id);
	pthread_mutex_lock(philo->eat_lock);
	philo->last_eat = time_now();
	philo->eaten_count++;
	pthread_mutex_unlock(philo->eat_lock);
	my_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
