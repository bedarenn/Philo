/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:12:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/09 13:18:39 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>
#include <stdio.h>

void	fork_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->fork.left);
	print_fork(philo->id, philo->arg);
	pthread_mutex_lock(&philo->fork.right);
	print_fork(philo->id, philo->arg);
}

void	fork_unlock(t_fork *fork)
{
	pthread_mutex_unlock(fork->left);
	if (fork->left != &fork->right)
		pthread_mutex_unlock(&fork->right);
}

void	*undertaker(t_philo *philo, t_tv t, void *ptr)
{
	fork_unlock(&philo->fork);
	pthread_mutex_lock(&philo->arg->m_end);
	if (!philo->arg->end)
	{
		print_died(t, philo->id, philo->arg);
		philo->arg->end = TRUE;
	}
	pthread_mutex_unlock(&philo->arg->m_end);
	return (ptr);
}

t_bool	get_end(t_arg *arg)
{
	t_bool	end;

	pthread_mutex_lock(&arg->m_end);
	end = arg->end;
	pthread_mutex_unlock(&arg->m_end);
	return (end);
}
