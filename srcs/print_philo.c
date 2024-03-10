/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:57:40 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/09 14:26:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>

void	print_fork(size_t id, t_arg *arg)
{
	t_tv	t;
	t_ltime	diff;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&arg->m_print);
	printf("%06li %zu has taken a fork\n",
		diff = diff_timeval(t, arg->start) / 1000,
		id);
	pthread_mutex_unlock(&arg->m_print);
}

void	print_eating(t_tv t, size_t id, t_arg *arg)
{
	pthread_mutex_lock(&arg->m_print);
	printf("%06li %zu is eating\n",
		diff_timeval(t, arg->start) / 1000,
		id);
	pthread_mutex_unlock(&arg->m_print);
}

void	print_sleeping(size_t id, t_arg *arg)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&arg->m_print);
	printf("%06li %zu is sleeping\n",
		diff_timeval(t, arg->start) / 1000,
		id);
	pthread_mutex_unlock(&arg->m_print);
}

void	print_thinking(size_t id, t_arg *arg)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&arg->m_print);
	printf("%06li %zu is thinking\n",
		diff_timeval(t, arg->start) / 1000,
		id);
	pthread_mutex_unlock(&arg->m_print);
}

void	print_died(t_tv t, size_t id, t_arg *arg)
{
	pthread_mutex_lock(&arg->m_print);
	printf("%06li %zu died\n",
		diff_timeval(t, arg->start) / 1000,
		id);
	pthread_mutex_unlock(&arg->m_print);
}
