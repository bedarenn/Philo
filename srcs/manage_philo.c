/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:23:37 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:37:22 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_thrd	*create_philos(size_t count, t_arg *arg)
{
	t_thrd	*list;
	t_thrd	*last;
	t_thrd	*new;
	size_t	i;

	i = 1;
	list = NULL;
	while (i <= count)
	{
		new = new_thrd(i, arg);
		if (!new)
		{
			free_philos(list);
			return (NULL);
		}
		add_thrd(&list, new);
		i++;
	}
	last = lastthrd(list);
	if (list && last)
		list->philo.fork.left = &last->philo.fork.right;
	return (list);
}

void	free_philos(t_thrd	*list)
{
	if (list->next)
		free_philos(list->next);
	free(list);
	//pthread_mutex_destroy(&list->philo.fork.right);
}
