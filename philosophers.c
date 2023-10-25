/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:30:18 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/23 15:49:32 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args_valid(char **av)
{
	if (ft_tatoi(av[1]) > PHILO_MAX || ft_tatoi(av[1]) <= 0)
		ft_error("philo num");
	if (ft_tatoi(av[2]) <= 0)
		ft_error("time2die");
	if (ft_tatoi(av[3]) <= 0)
		ft_error("time2eat");
	if (ft_tatoi(av[4]) <= 0)
		ft_error("time2sleep");
	if (av[5] && ft_tatoi(av[5]) < 0)
		ft_error("philo must eat");
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (!(ac >= 5 && ac <= 6))
		ft_error("arg count");
	if (check_args_valid(av) == 1)
		return (EXIT_FAILURE);
	initialize_program(&program, philos);
	initialize_forks(forks, ft_tatoi(av[1]));
	initialize_philos(philos, &program, forks, av);
	thread_create(&program, forks);
	destroyer(NULL, &program, forks);
	return (0);
}
