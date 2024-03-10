/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_emoji.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:24:47 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/09 14:24:56 by bedarenn         ###   ########.fr       */
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
	printf("%06li | %zu | has taken a fork %s\n",
		diff = diff_timeval(t, arg->start) / 1000,
		id,
		"\xF0\x9F\x8D\xB4");
	pthread_mutex_unlock(&arg->m_print);
}

void	print_eating(t_tv t, size_t id, t_arg *arg)
{
	pthread_mutex_lock(&arg->m_print);
	printf("%06li | %zu | is eating        %s\n",
		diff_timeval(t, arg->start) / 1000,
		id,
		"\xF0\x9F\x8D\x9C");
	pthread_mutex_unlock(&arg->m_print);
}

void	print_sleeping(size_t id, t_arg *arg)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&arg->m_print);
	printf("%06li | %zu | is sleeping      %s\n",
		diff_timeval(t, arg->start) / 1000,
		id,
		"\xF0\x9F\x92\xA4");
	pthread_mutex_unlock(&arg->m_print);
}

void	print_thinking(size_t id, t_arg *arg)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&arg->m_print);
	printf("%06li | %zu | is thinking      %s\n",
		diff_timeval(t, arg->start) / 1000,
		id,
		"\xF0\x9F\x92\xA1");
	pthread_mutex_unlock(&arg->m_print);
}

void	print_died(t_tv t, size_t id, t_arg *arg)
{
	pthread_mutex_lock(&arg->m_print);
	printf("%06li | %zu | died             %s\n",
		diff_timeval(t, arg->start) / 1000,
		id,
		"\xF0\x9F\x92\x80");
	pthread_mutex_unlock(&arg->m_print);
}
