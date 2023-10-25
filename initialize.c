/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:12:11 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:27:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_input(t_philo *philo, char **av)
{
	philo->time_to_die = ft_tatoi(av[2]);
	philo->time_to_eat = ft_tatoi(av[3]);
	philo->time_to_sleep = ft_tatoi(av[4]);
	philo->philo_num = ft_tatoi(av[1]);
	if (av[5])
		philo->need_eat_num = ft_tatoi(av[5]);
	else
		philo->need_eat_num = -1;
}

void	initialize_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_tatoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].eaten_count = 0;
		initialize_input(&philos[i], av);
		philos[i].start_time = time_now();
		philos[i].last_eat = time_now();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].eat_lock = &program->eat_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].philo_num - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	initialize_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	initialize_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->eat_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}
