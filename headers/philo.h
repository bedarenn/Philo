/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:33 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:56:37 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <w_const.h>
# include <w_struct.h>

/*    Set arg    */
t_arg	set_arg(int argc, char **argv2);
int		check_arg(int count, t_arg	arg);

/*    Philo init    */
t_thrd	*create_philos(size_t count, t_arg *arg);
void	free_philos(t_thrd	*list);
	/*    Theard init    */
t_thrd	*new_thrd(size_t id, t_arg *arg);
t_thrd	*add_thrd(t_thrd **list0, t_thrd *new);
t_thrd	*lastthrd(t_thrd *list);

/*    Thread's launcher    */
void	list_map(t_thrd *list, void (*f)(t_thrd *));
void	lauch_thrd(t_thrd *thrd);
void	lauch_thrd_time(t_thrd *thrd);
void	wait_thrd(t_thrd *thrd);

/*    Philosopher's routine    */
void	*m_philo(void *ptr);
void	*m_philo_time(void *ptr);

/*    Manage Fork    */
t_bool	fork_lock(t_philo *philo);
t_bool	fork_unlock(t_fork *fork);
t_bool	undertaker(t_philo *philo, t_tv t);

/*    Print philo    */
t_bool	print_fork(t_philo *philo);
t_bool	print_eating(t_tv t, t_philo *philo);
t_bool	print_sleeping(t_philo *philo);
t_bool	print_thinking(t_philo *philo);
t_bool	print_died(t_tv t, t_philo *philo);

/*    WATI_SLEEP    */
t_philo	*wati_sleep(t_philo *philo, t_tv last, t_ltime time);

/*    TOOLS    */
int		w_atoi(const char *nptr);
t_ltime	diff_timeval(t_tv t1, t_tv t2);

#endif