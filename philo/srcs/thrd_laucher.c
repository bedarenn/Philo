/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_laucher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:12 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/24 18:46:44 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thrd			*thrd_laucher(t_thrd *thrd);

static t_thrd	*list_map(t_thrd *list);

t_thrd	*thrd_laucher(t_thrd *thrd)
{
	return (list_map(thrd));
}

static t_thrd	*list_map(t_thrd *list)
{
	while (list)
	{
		set_pvar(&list->philo.i, 0);
		set_pvar(&list->philo.meal, get_time());
		if (pthread_create(&list->pthread, NULL, &m_philo, &list->philo))
			return (NULL);
		list = list->next;
	}
	return (list);
}
