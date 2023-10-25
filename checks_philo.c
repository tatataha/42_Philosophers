/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:37:09 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:41:59 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	messager(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = (time_now() - philo->start_time);
	if (!dieorlie(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	philo_dead(t_philo *philo, size_t time_to_die)
{
	size_t	time;

	pthread_mutex_lock(philo->eat_lock);
	time = time_now();
	if (time - philo->last_eat >= time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->eat_lock), 1);
	pthread_mutex_unlock(philo->eat_lock);
	return (0);
}

int	dead_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philo_num)
	{
		if (philo_dead(&philo[i], philo[i].time_to_die) != 0)
		{
			messager("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	need_eat_check(t_philo *philo)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	if (philo[0].need_eat_num == -1)
		return (0);
	while (i < philo[0].philo_num)
	{
		pthread_mutex_lock(philo[i].eat_lock);
		if (philo[i].eaten_count >= philo[i].need_eat_num)
			ok++;
		pthread_mutex_unlock(philo[i].eat_lock);
		i++;
	}
	if (ok == philo[0].philo_num)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*all_right(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
		if (dead_checker(philo) == 1 || need_eat_check(philo) == 1)
			break ;
	return (pointer);
}
