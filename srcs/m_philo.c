/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:41:47 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/10 17:04:38 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philo.h"

static void	*philo(t_philo *philo);

void	*m_philo(void *ptr)
{
	if (!philo(ptr))
		return (print_died(ptr));
	return (ptr);
}

static void	*philo(t_philo *philo)
{
	if (&philo->cutlery.left == philo->cutlery.right)
	{
		usleep(philo->rules->dietime);
		return (NULL);
	}
	gettimeofday(&philo->meal, NULL);
	if ((philo->id % 2))
		usleep(philo->rules->dietime / 2);
	philo->i = 0;
	while (1)
	{
		if (!m_philo_eat(philo))
			return (NULL);
		if (philo->rules->eatend > 0 && philo->i > philo->rules->eatend)
			break ;
		if (!m_philo_sleep(philo))
			return (NULL);
	}
	return (philo);
}
