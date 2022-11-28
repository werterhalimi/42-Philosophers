/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:57:59 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/28 22:45:20 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	new_table(int no_philo,
		int time_to_die,
		int time_to_eat,
		int time_to_sleep)
{
	t_table	ret;
	int		i;
	pthread_t *threads;

	ret.philos = malloc(sizeof(t_philo) * (no_philo));
	ret.forks = malloc(sizeof(enum e_state) * (no_philo));
	threads = malloc(sizeof(*threads) * (no_philo));
	ret.no_philo = no_philo;
	ret.time_to_die = time_to_die;
	ret.time_to_eat = time_to_eat;
	ret.time_to_sleep = time_to_sleep;
	ret.total_eat = 0;
//	pthread_mutex_init(ret.mutex, NULL);
	i = 0;
	while (i < no_philo)
	{
		ret.forks[i] = Fork;
		i++;
	}
	i = 0;
	while (i < no_philo)
	{
		((t_philo *)ret.philos)[i] = new_philo(i,ret, threads + i);
		if (i % 2)
			usleep(200000);
		run_philo(&((t_philo *)ret.philos)[i]);
		i++;
	}
	return (ret);
}
