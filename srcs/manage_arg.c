/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:58:02 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:37:22 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <unistd.h>

t_arg	set_arg(int argc, char **argv2)
{
	t_arg	arg;

	arg.dietime = w_atoi(argv2[0]) * MS;
	arg.eattime = w_atoi(argv2[1]) * MS;
	arg.sleeptime = w_atoi(argv2[2]) * MS;
	if (argc < 6)
		arg.eatend = LONG_MAX;
	else
		arg.eatend = w_atoi(argv2[3]);
	return (arg);
}

t_bool	check_arg(int count, t_arg	arg)
{
	if (count <= 0
		|| arg.dietime < 0
		|| arg.eattime < 0
		|| arg.sleeptime < 0
		|| arg.eatend < 0)
	{
		write(2, "Error\n", 7);
		return (FALSE);
	}
	return (TRUE);
}
