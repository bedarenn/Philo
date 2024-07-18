/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_philo_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:17:23 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:53:37 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "w_print.h"

void		*m_philo_meal(t_philo *philo);
void		*m_philo_sleep(t_philo *philo);

static void	*m_philo_lock(t_philo *philo);
static void	*m_philo_eat(t_philo *philo);
static void	*m_philo_unlock(t_philo *philo);

void	*m_philo_meal(t_philo *philo)
{
	if (!m_philo_lock(philo))
		return (NULL);
	if (!m_philo_eat(philo))
		return (NULL);
	if (!m_philo_unlock(philo))
		return (NULL);
	return (philo);
}

void	*m_philo_sleep(t_philo *philo)
{
	if (!m_print(philo, SLEEP))
		return (NULL);
	wati_sleep(philo, philo->rules->sleeptime);
	if (!m_print(philo, THINK))
		return (NULL);
	return (philo);
}

static void	*m_philo_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->cutlery.left);
	if (!m_print(philo, FORK_))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		return (NULL);
	}
	pthread_mutex_lock(philo->cutlery.right);
	if (!m_print(philo, FORK_))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		pthread_mutex_unlock(philo->cutlery.right);
		return (NULL);
	}
	return (philo);
}

static void	*m_philo_eat(t_philo *philo)
{
	if (!m_print(philo, EAT__))
	{
		pthread_mutex_unlock(&philo->cutlery.left);
		pthread_mutex_unlock(philo->cutlery.right);
		return (NULL);
	}
	set_pvar(&philo->meal, philo->t);
	wati_sleep(philo, philo->rules->eattime);
	set_incr(&philo->i);
	return (philo);
}

static void	*m_philo_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->cutlery.left);
	pthread_mutex_unlock(philo->cutlery.right);
	return (philo);
}
