/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:27:42 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:53:54 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

t_thrd			*thrd_create(t_ltime count, t_arg *arg);

static t_thrd	*new_thrd(size_t id, t_arg *arg);

t_thrd	*thrd_create(t_ltime count, t_arg *arg)
{
	t_thrd	*first;
	t_thrd	*last;
	t_thrd	*new;
	t_ltime	i;

	first = new_thrd(1, arg);
	last = first;
	i = 1;
	while (i < count)
	{
		new = new_thrd(++i, arg);
		if (!new)
			return (NULL);
		last->philo.cutlery.right = &new->philo.cutlery.left;
		last->next = new;
		last = new;
	}
	last->philo.cutlery.right = &first->philo.cutlery.left;
	return (first);
}

static t_thrd	*new_thrd(size_t id, t_arg *arg)
{
	t_thrd	*ptr;

	ptr = malloc(sizeof(t_thrd));
	if (ptr)
	{
		ptr->next = NULL;
		ptr->philo.id = id;
		ptr->philo.rules = arg;
		pthread_mutex_init(&ptr->philo.cutlery.left, NULL);
		pthread_mutex_init(&ptr->philo.meal.mutex, NULL);
		pthread_mutex_init(&ptr->philo.i.mutex, NULL);
	}
	return (ptr);
}
