/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:53:40 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 23:53:43 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_eat_time(t_philo *philo, long now)
{
	if (now - philo->last_ate >= philo->table->time_to_die)
	{
		philo->table->finished = 1;
		printf("%i est mort - %ld\n", philo->position, now);
		exit(0);
	}
}

void	take_fork(t_philo *philo, int right, int left, t_table *table)
{
	right = philo->position + 1;
	left = philo->position;
	if (philo->position == table->no_philo - 1)
		right = 0;
	if (!philo->left)
	{
		pthread_mutex_lock(&table->mutex[left]);
		if (table->forks[left] == Fork)
		{
			table->forks[left] = Eating;
			philo->left = 1;
		}
		pthread_mutex_unlock(&table->mutex[left]);
	}
	if (!philo->right)
	{
		pthread_mutex_lock(&table->mutex[right]);
		if (table->forks[right] == Fork)
		{
			table->forks[right] = Eating;
			philo->right = 1;
		}
		pthread_mutex_unlock(&table->mutex[right]);
	}
}
