/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:52:01 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:37:56 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dieorlie(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*one_day_of_philo(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		my_usleep(1);
	while (!dieorlie(philo))
	{
		philo_eat(philo);
		philo_zzz(philo);
		philo_think(philo);
	}
	return (pointer);
}

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	mthread;
	int			i;

	if (pthread_create(&mthread, NULL, &all_right, program->philos) != 0)
		destroyer("Thread creation error !", program, forks);
	i = 0;
	while (i < program->philos[0].philo_num)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &one_day_of_philo,
				&program->philos[i]) != 0)
			destroyer("Thread creation error !", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(mthread, NULL) != 0)
		destroyer("Thread join error !", program, forks);
	while (i < program->philos[0].philo_num)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroyer("Thread join error !", program, forks);
		i++;
	}
	return (0);
}
