/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:43:02 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/30 00:44:02 by shalimi          ###   ########.fr       */
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
# include "params.h"

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
	void			*(*run)(void*);
}	t_philo;

void		*run(void *philo);
void		think(t_philo *philo);
void		run_philo(t_philo *philo);
void		check_eat_time(t_philo *philo, long now);
void		take_fork(t_philo *philo, int right, int left, t_table *table);
t_params	parse(int argc, char **argv);
long		get_now(void);
t_philo		new_philo(int position, t_table *table, pthread_t *thread);
t_table		*new_table(t_params params);
#endif
