/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:53:40 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/30 14:46:56 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	philo->state = Thinking;
	print(philo, get_now(), "is thinking");
}

int	lock_fork(t_philo *philo, t_table *table, int position)
{
	pthread_mutex_lock(&table->mutex[position]);
	print(philo, get_now(), "has taken a fork");
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

void	print(t_philo *philo, long stamp, char *message)
{
	if (philo->table->finished != 1)
		printf("%ld %i %s\n", stamp, philo->position, message);
}
