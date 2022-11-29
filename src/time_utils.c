/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:21:42 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/28 21:54:19 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_now(void)
{
	struct timeval	now;
	static long		start;

	gettimeofday(&now, 0);
	if (start == 0)
	{
		start = now.tv_sec * 1000 + now.tv_usec / 1000;
	}
	return ((now.tv_sec * 1000 + now.tv_usec / 1000) - start);
}
