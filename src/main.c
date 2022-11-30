/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:54:53 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/30 12:01:51 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	finish(t_table *table)
{
	table->finished = 1;
	free(table->philos);
	free(table->forks);
	free(table->threads);
	free(table->mutex);
	free(table);
	exit(0);
}

void	join_thread(t_table *table)
{
	int			i;
	t_philo		philo;

	i = 0;
	while (i < table->no_philo)
	{
		philo = ((t_philo *)table->philos)[i];
		if (pthread_join(*(philo.thread), NULL) != 0)
			exit(1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table		*table;
	t_params	params;
	int			i;
	t_philo		philo;

	params = parse(argc, argv);
	table = new_table(params);
	i = 0;
	while (1)
	{
		i = 0;
		while (i < table->no_philo)
		{
			philo = ((t_philo *) table->philos)[i];
			if (get_now() - philo.last_ate >= params.time_to_die
				|| (philo.no_eat >= table->total_eat
					&& table->total_eat != 0))
			{
				printf("%ld %i died\n", get_now(), philo.position);
				finish(table);
			}
			i++;
		}
	}
	join_thread(table);
}
