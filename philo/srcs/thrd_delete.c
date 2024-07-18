/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:16:01 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:37:19 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

void			thrd_delete(t_thrd **list);

static void		_thrd_delete(t_thrd *list);

void	thrd_delete(t_thrd **list)
{
	if (list)
	{
		_thrd_delete(*list);
		*list = NULL;
	}
}

static void	_thrd_delete(t_thrd *list)
{
	if (list)
	{
		pthread_join(list->pthread, NULL);
		_thrd_delete(list->next);
		free(list);
	}
}
