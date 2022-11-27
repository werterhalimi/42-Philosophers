/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_set.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:51:09 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/27 18:54:14 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_SET_H
# define TABLE_SET_H

typedef struct s_table_set
{
	pthread_mutex_t	mutex;
	int		state;
}	t_table_set;
#endif
