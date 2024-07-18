/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:02:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:06:39 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philo.h"

int		w_atoi(const char *nptr);
t_ltime	get_time(void);
void	*wati_sleep(t_philo *philo, t_ltime nb);

t_ltime	get_time(void)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	w_atoi(const char *nptr)
{
	int		s;
	size_t	n;

	while (((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr == '-')
	{
		s = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		s = 1;
		nptr++;
	}
	else
		s = 1;
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - 48);
		nptr++;
	}
	return (s * n);
}

void	*wati_sleep(t_philo *philo, t_ltime nb)
{
	t_ltime	t;

	philo->t = get_time();
	t = philo->t;
	while (philo->t - t < nb)
	{
		usleep(150);
		if (!check_end(philo))
			return (NULL);
		philo->t = get_time();
	}
	return (philo);
}
