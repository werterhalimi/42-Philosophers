/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:53:40 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/30 00:41:43 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_eat_time(t_philo *philo, long now)
{
	if (now - philo->last_ate >= philo->table->time_to_die)
	{
		philo->table->finished = 1;
		printf("%ld %i died\n", get_now(), philo->position);
		exit(0);
	}
}

void	lock_fork(t_philo *philo, t_table *table, int position)
{
	pthread_mutex_lock(&table->mutex[position]);
	if (table->forks[position] == Fork)
	{
		table->forks[position] = Eating;
		printf("%ld %i has taken a fork\n", get_now(), philo->position);
	}
	pthread_mutex_unlock(&table->mutex[position]);
}

void	take_fork(t_philo *philo, int right, int left, t_table *table)
{
	right = philo->position + 1;
	left = philo->position;
	if (philo->position == table->no_philo - 1)
		right = 0;
	if (!philo->left)
	{
		lock_fork(philo, table, left);
		philo->left = 1;
	}
	if (!philo->right)
	{
		lock_fork(philo, table, right);
		philo->right = 1;
	}
}
