/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:41:47 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/22 17:50:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "philo.h"

void		*m_philo(void *ptr);

static void	*philo(t_philo *philo);

void	*m_philo(void *ptr)
{
	return (philo(ptr));
}

static void	*philo(t_philo *philo)
{
	if (&philo->cutlery.left == philo->cutlery.right)
		wati_sleep(philo, philo->rules->dietime);
	if ((philo->id & 1))
		wati_sleep(philo, philo->rules->eattime * 0.9 + 1);
	while (check_end(philo))
	{
		if (!m_philo_meal(philo))
			return (NULL);
		if (!check_i(philo))
			break ;
		if (!m_philo_sleep(philo))
			return (NULL);
	}
	return (philo);
}
