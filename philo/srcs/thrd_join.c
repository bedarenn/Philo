/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:23:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:53:48 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "w_print.h"
#include "philo.h"

void		thrd_join(t_thrd *list, t_ltime count);

static bool	thrd_checker(t_thrd *list, t_ltime count);
static void	philo_dead(t_philo *philo);

void	thrd_join(t_thrd *list, t_ltime count)
{
	while (thrd_checker(list, count))
		usleep(1000);
}

static bool	thrd_checker(t_thrd *list, t_ltime count)
{
	t_ltime	i;

	i = 0;
	while (list)
	{
		if (!check_end(&list->philo))
			return (false);
		if (!check_i(&list->philo))
			i++;
		if (!check_meal(&list->philo))
		{
			philo_dead(&list->philo);
			return (false);
		}
		list = list->next;
	}
	if (i >= count)
		return (false);
	return (true);
}

static void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->var.m_print);
	pthread_mutex_lock(&philo->rules->var.m_end);
	philo->rules->var.end = true;
	printf(DEAD_, get_time() - philo->rules->var.start, philo->id);
	pthread_mutex_unlock(&philo->rules->var.m_end);
	pthread_mutex_unlock(&philo->rules->var.m_print);
}
