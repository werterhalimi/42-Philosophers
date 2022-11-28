/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:54:53 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/28 23:00:02 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	(void) argc;
	(void) argv;
	table = new_table(1,800, 200, 200);
	int	i = 0;
	while (i < table.no_philo)
	{
		t_philo philo = ((t_philo *)table.philos)[i];
		if (pthread_join(*(philo.thread), NULL) != 0) {
        	return 5;
    	}
		i++;
	}
	return (0);
}
