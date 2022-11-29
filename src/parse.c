/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <shalimi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:55:41 by shalimi           #+#    #+#             */
/*   Updated: 2022/11/29 03:04:25 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 1;
	while ((*str >= 10 && *str <= 13) || *str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	if (*str != 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (ret * i);
}

t_params	parse(int argc, char **argv)
{
	int				i;
	t_params		params;
	int				*arr[5];

	arr[0] = &params.no_philo;
  	arr[1] = &params.time_to_die;
  	arr[2] = &params.time_to_eat;
	arr[3] = &params.time_to_sleep;
	arr[4] = &params.total_eat;
	if (argc < 5)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	*(arr[4]) = 0;
	while (i < argc - 1)
	{
		*(arr[i]) = ft_atoi(argv[i + 1]);
		if (*(arr[i]) <= 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (params);
}
