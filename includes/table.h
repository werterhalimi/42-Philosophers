/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:57:28 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 02:03:42 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H
# include "philosophers.h"

typedef struct s_table
{
	enum e_state	*forks;
	pthread_mutex_t	*mutex;
	pthread_t		*threads;
	void			*philos;
	int				no_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_eat;
	int				finished;
}	t_table;
#endif
