/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:28:33 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 02:30:03 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef struct s_params
{
	int				no_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_eat;
}	t_params;
#endif
