/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:46:02 by bedarenn          #+#    #+#             */
/*   Updated: 2024/04/09 15:34:55 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>
#include <unistd.h>

static void	*manage_meal(t_philo *philo, t_meal *meal);
static void	*sleep_and_think(t_philo *philo, t_tv last);
static void	*die_alone(t_philo *philo, t_meal *meal);

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
		if (!sleep_and_think(philo, meal.last))
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
		if (!sleep_and_think(philo, meal.last))
			return (NULL);
	}
	return (ptr);
}

static void	*manage_meal(t_philo *philo, t_meal *meal)
{
	t_ltime	diff;

	if (!fork_lock(philo))
		return (NULL);
	gettimeofday(&meal->actual, NULL);
	diff = diff_timeval(meal->actual, meal->last);
	if (diff > philo->arg->dietime)
		return (undertaker(philo, meal->actual, NULL));
	meal->last = meal->actual;
	if (!print_eating(meal->actual, philo))
	{
		fork_unlock(&philo->fork);
		return (NULL);
	}
	usleep(philo->arg->eattime);
	fork_unlock(&philo->fork);
	return (philo);
}

static void	*sleep_and_think(t_philo *philo, t_tv last)
{
	(void)last;
	if (!print_sleeping(philo))
		return (NULL);
	usleep(philo->arg->sleeptime);
	if (!print_thinking(philo))
		return (NULL);
	return (philo);
}

static void	*die_alone(t_philo *philo, t_meal *meal)
{
	t_ltime	diff;

	if (philo->fork.left == &philo->fork.right)
	{
		usleep(philo->arg->dietime);
		gettimeofday(&meal->actual, NULL);
		diff = diff_timeval(meal->actual, meal->last);
		if (diff > philo->arg->dietime)
			return (undertaker(philo, meal->actual, NULL));
	}
	return (philo);
}
