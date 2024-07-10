/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undertaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:17:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/10 16:58:23 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "philo.h"

void	*undertaker(t_philo *philo)
{
	t_tv	t;

	pthread_mutex_lock(&philo->rules->var.m_end);
	if (philo->rules->var.end)
	{
		pthread_mutex_unlock(&philo->rules->var.m_end);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->rules->var.m_end);
	gettimeofday(&t, NULL);
	if (diff_timeval(t, philo->meal) > philo->rules->dietime)
		return (NULL);
	return (philo);
}

void	*print_died(t_philo *philo)
{
	t_tv	t;
	t_ltime	diff;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->rules->var.m_end);
	if (!philo->rules->var.end)
	{
		philo->rules->var.end = true;
		diff = diff_timeval(t, philo->rules->var.start) / 1000;
		pthread_mutex_lock(&philo->rules->var.m_print);
		printf("%06li | %zu | died             %s\n",
			diff, philo->id, "\xF0\x9F\x92\x80");
		pthread_mutex_unlock(&philo->rules->var.m_print);
	}
	pthread_mutex_unlock(&philo->rules->var.m_end);
	return (NULL);
}
