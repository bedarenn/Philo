/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_laucher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:12 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/25 17:11:46 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool			thrd_laucher(t_thrd *thrd);

bool			list_map(t_thrd *list);

bool	thrd_laucher(t_thrd *thrd)
{
	return (list_map(thrd));
}

bool	list_map(t_thrd *list)
{
	while (list)
	{
		set_pvar(&list->philo.i, 0);
		set_pvar(&list->philo.meal, get_time());
		if (pthread_create(&list->pthread, NULL, &m_philo, &list->philo))
			return (false);
		list = list->next;
	}
	return (true);
}
