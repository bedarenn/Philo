/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:15:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/24 16:35:30 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <philo.h>
#include <stdio.h>

static void	wati_usleep(t_ltime *time, t_ltime w);

t_philo	*wati_sleep(t_philo *philo, t_tv last, t_ltime time)
{
	t_ltime	diff;
	t_tv	act;

	while (time > 0)
	{
		if (philo->arg->end)
			return (NULL);
		gettimeofday(&act, NULL);
		diff = diff_timeval(act, last);
		if (diff > philo->arg->dietime)
			return (undertaker(philo, act, NULL));
		if (time > MAX * MS)
			wati_usleep(&time, MAX * MS);
		else
			wati_usleep(&time, time);
	}
	return (philo);
}

static void	wati_usleep(t_ltime *time, t_ltime w)
{
	usleep(w);
	*time -= w;
}
