/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:57:59 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/30 13:24:07 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*create_table(t_params params)
{
	t_table	*ret;

	ret = malloc(sizeof(*ret));
	ret->philos = malloc(sizeof(t_philo) * (params.no_philo));
	ret->forks = malloc(sizeof(enum e_state) * (params.no_philo));
	ret->threads = malloc(sizeof(*ret->threads) * (params.no_philo));
	ret->mutex = malloc(sizeof(*ret->mutex) * (params.no_philo));
	ret->no_philo = params.no_philo;
	ret->time_to_die = params.time_to_die;
	ret->time_to_eat = params.time_to_eat;
	ret->time_to_sleep = params.time_to_sleep;
	ret->total_eat = params.total_eat;
	ret->finished = 0;
	return (ret);
}

t_table	*new_table(t_params params)
{
	t_table	*ret;
	int		i;

	ret = create_table(params);
	i = 0;
	while (i < params.no_philo)
	{
		ret->forks[i] = Fork;
		pthread_mutex_init(ret->mutex + i, NULL);
		i++;
	}
	i = 0;
	while (i < params.no_philo)
	{
		((t_philo *)ret->philos)[i] = new_philo(i, ret, ret->threads + i);
		if (i % 2)
			usleep(1000000 / 200);
		run_philo(&((t_philo *)ret->philos)[i]);
		i++;
	}
	return (ret);
}
