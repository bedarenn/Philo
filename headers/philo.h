/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:33 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/09 13:18:53 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <w_const.h>
# include <w_struct.h>

int		w_atoi(const char *nptr);

/*    Manage t_tv    */
void	print_timeval(t_tv t);
t_ltime	diff_timeval(t_tv t1, t_tv t2);
void	*m_gettime(void *t);

/*    Set arg    */
t_arg	set_arg(int argc, char **argv2);
int		check_arg(int count, t_arg	arg);

/*    Create philo    */
t_thrd	*new_thrd(size_t id, t_arg *arg);
t_thrd	*add_thrd(t_thrd **list0, t_thrd *new);
t_thrd	*lastthrd(t_thrd *list);

/*    Create philosophers    */
t_thrd	*create_philos(size_t count, t_arg *arg);
void	free_philos(t_thrd	*list);

/*    thread's launcher    */
void	list_map(t_thrd *list, void (*f)(t_thrd *));
void	lauch_thrd(t_thrd *thrd);
void	lauch_thrd_time(t_thrd *thrd);
void	wait_thrd(t_thrd *thrd);
void	print_thrd(t_thrd *thrd);

/*    Philosopher's routine    */
void	*m_philo(void *ptr);
void	*m_philo_time(void *ptr);

/*    Manage Fork    */
void	fork_lock(t_philo *philo);
void	fork_unlock(t_fork *fork);
void	*undertaker(t_philo *philo, t_tv t, void *ptr);
int		get_end(t_arg *arg);

/*    Print philo    */
void	print_fork(size_t id, t_arg *arg);
void	print_eating(t_tv t, size_t id, t_arg *arg);
void	print_sleeping(size_t id, t_arg *arg);
void	print_thinking(size_t id, t_arg *arg);
void	print_died(t_tv t, size_t id, t_arg *arg);

#endif