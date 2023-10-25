/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:30:22 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:40:52 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int num)
{
	return (num >= '0' && num <= '9');
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	ft_check_arg(char *str)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit(str[i]) && str[i] != '+')
		ft_error("arg type");
	if ((str[i] == '+') && !ft_isdigit(str[i + 1]))
		ft_error("arg type");
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("arg type");
		i++;
	}
}

int	ft_tatoi(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	ft_check_arg(str);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if (res > 2147483647)
			ft_error("max int");
	}
	if ((res * sign) == 2147483648)
		ft_error("max int");
	return ((int)res * sign);
}
