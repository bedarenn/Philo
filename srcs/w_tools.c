/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:02:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/04 18:04:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ltime	diff_timeval(t_tv t1, t_tv t2)
{
	t_ltime	t;

	t = (t1.tv_sec - t2.tv_sec) * S_US + (t1.tv_usec - t2.tv_usec);
	return (t);
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
