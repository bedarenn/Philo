/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thrd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:53:15 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/01 15:55:49 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <w_struct.h>
#include <stdlib.h>

t_thrd	*new_thrd(size_t id, t_arg *arg)
{
	t_thrd	*ptr;

	ptr = malloc(sizeof(t_thrd));
	if (ptr)
	{
		ptr->next = NULL;
		ptr->philo.id = id;
		ptr->philo.arg = arg;
		pthread_mutex_init(&ptr->philo.fork.right, NULL);
	}
	return (ptr);
}

t_thrd	*add_thrd(t_thrd **list0, t_thrd *new)
{
	t_thrd	*list;

	if (!list0 || !new)
		return (NULL);
	if (!*list0)
	{
		*list0 = new;
		return (*list0);
	}
	list = *list0;
	while (list->next)
		list = list->next;
	list->next = new;
	new->philo.fork.left = &list->philo.fork.right;
	return (*list0);
}

t_thrd	*lastthrd(t_thrd *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
