/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:30:15 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:26:02 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *str)
{
	if (ft_strcmp(str, "arg count") == 0)
		ft_putstr_fd("Wrong argument count !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "arg type") == 0)
		ft_putstr_fd("Wrong argument type !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "max int") == 0)
		ft_putstr_fd("Your argument bigger than maximum integer !\n",
			STDERR_FILENO);
	else if (ft_strcmp(str, "philo num") == 0)
		ft_putstr_fd("Invalid philosophers count !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "time2die") == 0)
		ft_putstr_fd("Invalid time to die !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "time2eat") == 0)
		ft_putstr_fd("Invalid time to eat !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "time2sleep") == 0)
		ft_putstr_fd("Invalid time to sleep !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "philo must eat") == 0)
		ft_putstr_fd("Invalid number of times each philosopher must eat\n", 2);
	else if (ft_strcmp(str, "gettime") == 0)
		ft_putstr_fd("\"gettimeofday()\" function error !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "Thread creation error !") == 0)
		ft_putstr_fd("Thread creation error !\n", STDERR_FILENO);
	else if (ft_strcmp(str, "Thread join error !") == 0)
		ft_putstr_fd("Thread join error !\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}
