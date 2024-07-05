/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:58:19 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 12:35:57 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_arg(t_arg *arg, int argc, char **argv)
{
	if (!arg)
		return (false);
	arg->dietime = w_atoi(argv[2]) * MS;
	arg->eattime = w_atoi(argv[3]) * MS;
	arg->sleeptime = w_atoi(argv[4]) * MS;
	if (arg->sleeptime < 0 || arg->eattime < 0 || arg->dietime < 0)
		return (false);
	if (argc == 6)
	{
		arg->eatend = w_atoi(argv[5]);
		if (arg->eatend < 0)
			return (false);
	}
	else
		arg->eatend = -1;
	arg->var.end = false;
	pthread_mutex_init(&arg->var.m_end, NULL);
	pthread_mutex_init(&arg->var.m_print, NULL);
	return (true);
}
