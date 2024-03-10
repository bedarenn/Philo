/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_timeval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:52:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/04 13:58:17 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>
#include <stdlib.h>

t_ltime	diff_timeval(t_tv t1, t_tv t2)
{
	t_ltime	t;

	t = (t1.tv_sec - t2.tv_sec) * 1000000 + (t1.tv_usec - t2.tv_usec);
	return (t);
}

void	print_timeval(t_tv t)
{
	printf("%li %li\n", t.tv_sec, t.tv_usec);
}

void	*m_gettime(void *t)
{
	gettimeofday(t, NULL);
	return (t);
}
