/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:57:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/28 16:58:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
