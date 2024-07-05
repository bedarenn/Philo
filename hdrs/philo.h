/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:23 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 15:05:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <w_struct.h>

t_ltime	diff_timeval(t_tv t1, t_tv t2);
int		w_atoi(const char *nptr);

bool	init_arg(t_arg *arg, int argc, char **argv);

t_thrd	*create_philos(t_ltime count, t_arg *arg);
void	clear_thrd(t_thrd **list);

void	list_map(t_thrd *list, void (*f)(t_thrd *));
void	lauch_thrd(t_thrd *thrd);

void	*m_philo(void *ptr);

void	*m_philo_eat(t_philo *philo);
void	*print_fork(t_philo *philo);
void	*print_eat(t_philo *philo);

void	*m_philo_sleep(t_philo *philo);
void	*print_sleep(t_philo *philo);
void	*print_think(t_philo *philo);

void	*undertaker(t_philo *philo);
void	*print_died(t_philo *philo);

#endif // PHILO_H