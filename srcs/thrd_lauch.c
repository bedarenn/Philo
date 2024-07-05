/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_lauch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:12 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 14:58:18 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
