/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:28:09 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:41:23 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroyer(char *errstr, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (errstr)
		ft_error(errstr);
	while (i < program->philos[0].philo_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->eat_lock);
	pthread_mutex_destroy(&program->write_lock);
}

int	my_usleep(size_t msecond)
{
	size_t	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < msecond)
		usleep(500);
	return (0);
}

size_t	time_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("gettime");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
