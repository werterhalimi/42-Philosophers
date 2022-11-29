/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:43:02 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 01:55:32 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <sys/time.h>
# include "state.h"
# include "table.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				left;
	int				right;
	int				position;
	int				no_eat;
	long			last_ate;
	long			last_slept;
	enum e_state	state;
	pthread_t		*thread;
	t_table			*table;
	void*			(*run)(void *);

} t_philo;

void	*run(void *philo);
void	run_philo(t_philo *philo);
long	get_now();
t_philo	new_philo(int position, t_table *table, pthread_t *thread);
t_table	*new_table(int no, int die, int eat, int sleep);
#endif
