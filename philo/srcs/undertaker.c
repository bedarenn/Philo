/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undertaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:17:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:53:01 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	*undertaker(t_philo *philo);
void	*check_end(t_philo *philo);
void	*check_i(t_philo *philo);
void	*check_meal(t_philo *philo);

void	*check_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->var.m_end);
	if (philo->rules->var.end)
	{
		pthread_mutex_unlock(&philo->rules->var.m_end);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->rules->var.m_end);
	return (philo);
}

void	*check_i(t_philo *philo)
{
	pthread_mutex_lock(&philo->i.mutex);
	if (philo->rules->eatend > 0 && philo->i.var >= philo->rules->eatend)
	{
		pthread_mutex_unlock(&philo->i.mutex);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->i.mutex);
	return (philo);
}

void	*check_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal.mutex);
	if (get_time() - philo->meal.var > philo->rules->dietime)
	{
		pthread_mutex_unlock(&philo->meal.mutex);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->meal.mutex);
	return (philo);
}
