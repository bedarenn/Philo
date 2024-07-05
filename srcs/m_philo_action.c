/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_philo_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:17:23 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 15:11:17 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philo.h"

static void	*m_philo_lock_left(t_philo *philo);
static void	*m_philo_lock_right(t_philo *philo);

void	*m_philo_eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (!m_philo_lock_right(philo))
			return (NULL);
	}
	else
	{
		if (!m_philo_lock_left(philo))
			return (NULL);
	}
	if (!print_eat(philo))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		pthread_mutex_unlock(philo->cutlery.right);
		return (NULL);
	}
	usleep(philo->rules->eattime);
	pthread_mutex_unlock(&philo->cutlery.left);
	pthread_mutex_unlock(philo->cutlery.right);
	if (!undertaker(philo))
		return (NULL);
	philo->i++;
	return (philo);
}

static void	*m_philo_lock_left(t_philo *philo)
{
	if (philo->rules->var.end)
		return (NULL);
	pthread_mutex_lock(&philo->cutlery.left);
	if (!undertaker(philo) || !print_fork(philo))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		return (NULL);
	}
	pthread_mutex_lock(philo->cutlery.right);
	if (!undertaker(philo) || !print_fork(philo))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		pthread_mutex_unlock(philo->cutlery.right);
		return (NULL);
	}
	return (philo);
}

static void	*m_philo_lock_right(t_philo *philo)
{
	if (philo->rules->var.end)
		return (NULL);
	pthread_mutex_lock(philo->cutlery.right);
	if (!undertaker(philo))
	{
		pthread_mutex_unlock(philo->cutlery.right);
		return (NULL);
	}
	print_fork(philo);
	pthread_mutex_lock(&philo->cutlery.left);
	if (!undertaker(philo))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		pthread_mutex_unlock(philo->cutlery.right);
		return (NULL);
	}
	print_fork(philo);
	return (philo);
}

void	*m_philo_sleep(t_philo *philo)
{
	if (!undertaker(philo))
		return (NULL);
	if (!print_sleep(philo))
		return (NULL);
	usleep(philo->rules->sleeptime);
	if (!undertaker(philo))
		return (NULL);
	if (!print_think(philo))
		return (NULL);
	return (philo);
}

