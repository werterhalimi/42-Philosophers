/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:53:40 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/30 12:56:03 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	philo->state = Thinking;
	printf("%ld %i is thinking\n", get_now(), philo->position);
}

int	lock_fork(t_philo *philo, t_table *table, int position)
{
	pthread_mutex_lock(&table->mutex[position]);
	printf("%ld %i has taken a fork\n", get_now(), philo->position);
	return (1);
}

void	take_fork(t_philo *philo, int right, int left, t_table *table)
{
	right = philo->position + 1;
	left = philo->position;
	if (philo->position == table->no_philo - 1)
		right = 0;
	if (!philo->left)
		philo->left = lock_fork(philo, table, left);
	if (!philo->right)
		philo->right = lock_fork(philo, table, right);
}
