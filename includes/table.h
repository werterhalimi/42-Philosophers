/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:57:28 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/27 23:36:48 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H
# include "philosophers.h"
# include "table_set.h"

typedef struct s_table
{
	enum e_state	*forks;
	pthread_mutex_t *mutex;
	void			*philos;
	int				no_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_eat;
}	t_table;
#endif
