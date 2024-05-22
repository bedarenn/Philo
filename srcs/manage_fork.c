/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:12:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:57:08 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

t_bool	fork_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->fork.left);
	if (!print_fork(philo))
	{
		pthread_mutex_unlock(philo->fork.left);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->fork.right);
	if (!print_fork(philo))
	{
		fork_unlock(&philo->fork);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	fork_unlock(t_fork *fork)
{
	pthread_mutex_unlock(fork->left);
	if (fork->left != &fork->right)
		pthread_mutex_unlock(&fork->right);
	return (FALSE);
}

t_bool	undertaker(t_philo *philo, t_tv t)
{
	fork_unlock(&philo->fork);
	pthread_mutex_lock(&philo->arg->m_end);
	if (!philo->arg->end)
	{
		print_died(t, philo);
		philo->arg->end = TRUE;
	}
	pthread_mutex_unlock(&philo->arg->m_end);
	return (FALSE);
}
