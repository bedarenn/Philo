/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:50:31 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 16:59:45 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	set_pvar(t_pvar *var, t_ltime value);
void	set_incr(t_pvar *var);
void	*m_print(t_philo *philo, char *format);

void	set_pvar(t_pvar *var, t_ltime value)
{
	pthread_mutex_lock(&var->mutex);
	var->var = value;
	pthread_mutex_unlock(&var->mutex);
}

void	set_incr(t_pvar *var)
{
	pthread_mutex_lock(&var->mutex);
	var->var++;
	pthread_mutex_unlock(&var->mutex);
}

void	*m_print(t_philo *philo, char *format)
{
	pthread_mutex_lock(&philo->rules->var.m_print);
	if (!check_end(philo))
	{
		pthread_mutex_unlock(&philo->rules->var.m_print);
		return (NULL);
	}
	philo->t = get_time();
	printf(format, philo->t - philo->rules->var.start, philo->id);
	pthread_mutex_unlock(&philo->rules->var.m_print);
	return (philo);
}
