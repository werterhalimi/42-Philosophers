/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:08:58 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 02:59:47 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	new_philo(int position, t_table *table, pthread_t *thread)
{
	t_philo	ret;

	ret.table = table;
	ret.position = position;
	ret.no_eat = 0;
	ret.left = 0;
	ret.right= 0;
	ret.thread = thread;
	ret.state = Thinking;
	ret.run = &run;
	return (ret);
}

void	run_philo(t_philo *philo)
{
	if (pthread_create(philo->thread, 0, philo->run,(void *) philo))
	{
		printf("Erreur");
		exit(1);
	}
}

void	eat(t_philo *philo)
{
	t_table *table;
	int		right;
	int		left;

	table = philo->table;
	right = philo->position + 1;
	left = philo->position;
	if (philo->position == table->no_philo - 1)
		right = 0;
	if (!philo->left)
	{
		pthread_mutex_lock(&table->mutex);
		if (table->forks[left] == Fork)
		{
			table->forks[left] = Eating;
			philo->left = 1;
		}
		pthread_mutex_unlock(&table->mutex);
	}
	if (!philo->right)
	{
		pthread_mutex_lock(&table->mutex);
		if (table->forks[right] == Fork)
		{
			table->forks[right] = Eating;
			philo->right = 1;
		}
		pthread_mutex_unlock(&table->mutex);
	}
	if (philo->right && philo->left)
	{
		philo->state = Eating;
		philo->last_ate = get_now();
		philo->no_eat += 1;
		printf("%i is eating - %ld\n", philo->position, philo->last_ate);
	}
	if (philo->table->total_eat != 0 && philo->no_eat >= philo->table->total_eat)
		philo->table->finished = 1;
}

void	sleep_philo(t_philo *philo)
{
	t_table *table;
	int		right;
	int		left;

	table = philo->table;
	right = philo->position + 1;
	left = philo->position;
	if (philo->position == table->no_philo - 1)
		right = 0;
	philo->state = Sleeping;
	pthread_mutex_lock(&philo->table->mutex);
	table->forks[left] = Fork;
	table->forks[right] = Fork;
	pthread_mutex_unlock(&philo->table->mutex);
	philo->left = 0;
	philo->right = 0;
	philo->last_slept = get_now();
	printf("%i is sleeping - %ld\n", philo->position, philo->last_slept);
}

void	*run(void *p)
{
	t_philo *philo = (t_philo *)p;
	long	now;
	philo->last_ate = get_now();
	while (philo->table->finished != 1)
	{
		now = get_now();
		if (philo->state == Sleeping)
		{
			if (now - philo->last_slept >= philo->table->time_to_eat)
				philo->state = Thinking;
		}
		if (philo->state == Eating)
		{
			if (now - philo->last_ate >= philo->table->time_to_eat)
				sleep_philo(philo);
		}
		if (philo->state == Thinking)
		{
			eat(philo);
		}
		if (now - philo->last_ate >= philo->table->time_to_die)
		{
			philo->table->finished = 1;
			printf("%i est mort - %ld\n", philo->position, now);
			break ;
		}
	}
	return (0);
}
