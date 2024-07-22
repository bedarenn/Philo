/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_laucher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:12 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/22 17:50:56 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		thrd_laucher(t_thrd *thrd);

static void	list_map(t_thrd *list);

void	thrd_laucher(t_thrd *thrd)
{
	list_map(thrd);
}

static void	list_map(t_thrd *list)
{
	while (list)
	{
		set_pvar(&list->philo.i, 0);
		set_pvar(&list->philo.meal, get_time());
		if (pthread_create(&list->pthread, NULL, &m_philo, &list->philo))
			printf("ERR\n");
		list = list->next;
	}
}
