/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:30:12 by muhcelik          #+#    #+#             */
/*   Updated: 2023/10/24 14:36:50 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

# define PHILO_MAX	200

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					eating;
	int					eaten_count;
	int					philo_num;
	int					need_eat_num;
	int					*dead;
	size_t				last_eat;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*eat_lock;
}						t_philo;

typedef struct s_program
{
	int					dead_flag;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		eat_lock;
	pthread_mutex_t		write_lock;
	t_philo				*philos;
}						t_program;

int		ft_error(char *str);
int		ft_tatoi(char *str);
int		dieorlie(t_philo *philo);
int		ft_isdigit(int num);
int		dead_checker(t_philo *philo);
int		ft_strcmp(char *s1, char *s2);
int		need_eat_check(t_philo *philo);
int		my_usleep(size_t msecond);
int		philo_dead(t_philo *philo, size_t time_to_die);
int		thread_create(t_program *program, pthread_mutex_t *forks);
void	philo_zzz(t_philo *philo);
void	*all_right(void *pointer);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	ft_putstr_fd(char *str, int fd);
void	*one_day_of_philo(void *pointer);
void	initialize_input(t_philo *philo, char **av);
void	messager(char *str, t_philo *philo, int id);
void	initialize_program(t_program *program, t_philo *philos);
void	initialize_forks(pthread_mutex_t *forks, int philo_num);
void	destroyer(char *errstr, t_program *program, pthread_mutex_t *forks);
void	initialize_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char **av);
size_t	time_now(void);

#endif