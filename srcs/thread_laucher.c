/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_laucher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:05 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:41:33 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "philo.h"

void	list_map(t_thrd *list, void (*f)(t_thrd *))
{
	while (list)
	{
		f(list);
		list = list->next;
	}
}

void	lauch_thrd(t_thrd *thrd)
{
	pthread_create(&thrd->pthread, NULL, &m_philo, &thrd->philo);
	usleep(1);
}

void	lauch_thrd_time(t_thrd *thrd)
{
	pthread_create(&thrd->pthread, NULL, &m_philo_time, &thrd->philo);
	usleep(1);
}

void	wait_thrd(t_thrd *thrd)
{
	pthread_join(thrd->pthread, NULL);
}
