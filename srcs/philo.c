/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:46:02 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:58:12 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "philo.h"

static t_bool	manage_meal(t_philo *philo, t_meal *meal);
static t_bool	sleep_and_think(t_philo *philo);
static t_bool	die_alone(t_philo *philo, t_meal *meal);

void	*m_philo(void *ptr)
{
	t_philo	*philo;
	t_meal	meal;

	philo = (t_philo *)ptr;
	gettimeofday(&meal.last, NULL);
	die_alone(philo, &meal);
	while (1)
	{
		if (!manage_meal(philo, &meal))
			return (NULL);
		if (!sleep_and_think(philo))
			return (NULL);
	}
	return (ptr);
}

void	*m_philo_time(void *ptr)
{
	t_philo	*philo;
	t_meal	meal;
	t_ltime	i;

	i = 0;
	philo = (t_philo *)ptr;
	gettimeofday(&meal.last, NULL);
	die_alone(philo, &meal);
	while (1)
	{
		if (!manage_meal(philo, &meal))
			return (NULL);
		i++;
		if (i >= philo->arg->eatend)
			return (ptr);
		if (!sleep_and_think(philo))
			return (NULL);
	}
	return (ptr);
}

static t_bool	manage_meal(t_philo *philo, t_meal *meal)
{
	t_ltime	diff;

	if (!fork_lock(philo))
		return (FALSE);
	gettimeofday(&meal->actual, NULL);
	diff = diff_timeval(meal->actual, meal->last);
	if (diff > philo->arg->dietime)
		return (undertaker(philo, meal->actual));
	meal->last = meal->actual;
	if (!print_eating(meal->actual, philo))
		return (fork_unlock(&philo->fork));
	usleep(philo->arg->eattime);
	fork_unlock(&philo->fork);
	return (TRUE);
}

static t_bool	sleep_and_think(t_philo *philo)
{
	if (!print_sleeping(philo))
		return (FALSE);
	usleep(philo->arg->sleeptime);
	if (!print_thinking(philo))
		return (FALSE);
	return (TRUE);
}

static t_bool	die_alone(t_philo *philo, t_meal *meal)
{
	t_ltime	diff;

	if (philo->fork.left == &philo->fork.right)
	{
		usleep(philo->arg->dietime);
		gettimeofday(&meal->actual, NULL);
		diff = diff_timeval(meal->actual, meal->last);
		if (diff > philo->arg->dietime)
			return (undertaker(philo, meal->actual));
	}
	return (TRUE);
}
