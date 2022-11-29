/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:54:53 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 02:49:10 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table		*table;
	t_params	params;
	int			i;
	t_philo		philo;

	params = parse(argc, argv);
	table = new_table(params);
	i = 0;
	while (i < table->no_philo)
	{
		philo = ((t_philo *)table->philos)[i];
		if (pthread_join(*(philo.thread), NULL) != 0)
			return (1);
		i++;
	}
	free(table->philos);
	free(table->forks);
	free(table->threads);
	free(table->mutex);
	free(table);
	return (0);
}
