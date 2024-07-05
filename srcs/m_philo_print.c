/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_philo_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:00:51 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 15:06:35 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	*print_fork(t_philo *philo)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->rules->var.m_print);
	if (!undertaker(philo))
	{
		pthread_mutex_unlock(&philo->rules->var.m_print);
		return (NULL);
	}
	printf("%06li | %zu | has taken a fork %s\n",
		diff_timeval(t, philo->rules->var.start) / 1000,
		philo->id,
		"\xF0\x9F\x8D\xB4");
	pthread_mutex_unlock(&philo->rules->var.m_print);
	return (philo);
}

void	*print_eat(t_philo *philo)
{
	gettimeofday(&philo->meal, NULL);
	pthread_mutex_lock(&philo->rules->var.m_print);
	if (!undertaker(philo))
	{
		pthread_mutex_unlock(&philo->rules->var.m_print);
		return (NULL);
	}
	printf("%06li | %zu | is eating        %s\n",
		diff_timeval(philo->meal, philo->rules->var.start) / 1000,
		philo->id,
		"\xF0\x9F\x8D\x9C");
	pthread_mutex_unlock(&philo->rules->var.m_print);
	return (philo);
}

void	*print_sleep(t_philo *philo)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->rules->var.m_print);
	if (!undertaker(philo))
	{
		pthread_mutex_unlock(&philo->rules->var.m_print);
		return (NULL);
	}
	printf("%06li | %zu | is sleeping      %s\n",
		diff_timeval(t, philo->rules->var.start) / 1000,
		philo->id,
		"\xF0\x9F\x92\xA4");
	pthread_mutex_unlock(&philo->rules->var.m_print);
	return (philo);
}

void	*print_think(t_philo *philo)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->rules->var.m_print);
	if (!undertaker(philo))
	{
		pthread_mutex_unlock(&philo->rules->var.m_print);
		return (NULL);
	}
	printf("%06li | %zu | is thinking      %s\n",
		diff_timeval(t, philo->rules->var.start) / 1000,
		philo->id,
		"\xF0\x9F\x92\xA1");
	pthread_mutex_unlock(&philo->rules->var.m_print);
	return (philo);
}
