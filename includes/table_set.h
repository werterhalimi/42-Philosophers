/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_set.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:51:09 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/27 22:17:43 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_SET_H
# define TABLE_SET_H
# include "philosophers.h"

typedef struct s_table_set
{
	enum e_state	state;
	pthread_mutex_t mutex;
} t_table_set;
#endif
