/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:47 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/27 22:17:41 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
#include "philosophers.h"

enum e_state
{
	Eating,
	Sleeping,
	Thinking,
	Dead,
	Fork
};
#endif
