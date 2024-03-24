/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_laucher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:05 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/24 16:54:36 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

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

void	print_thrd(t_thrd *thrd)
{
	printf("l:%p r:%p | ", thrd->philo.fork.left,
		&thrd->philo.fork.right);
}
