/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:23 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/25 17:09:43 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include "struct_philo.h"

/**** ROUTINE ****/

void	*m_philo(void *ptr);

void	*m_philo_meal(t_philo *philo);
void	*m_philo_sleep(t_philo *philo);

void	*undertaker(t_philo *philo);
void	*check_end(t_philo *philo);
void	*check_i(t_philo *philo);
void	*check_meal(t_philo *philo);

/**** MAIN ****/

bool	init_arg(t_arg *arg, int argc, char **argv);

t_thrd	*thrd_create(t_ltime count, t_arg *arg);
bool	thrd_laucher(t_thrd *thrd);
void	thrd_join(t_thrd *list, t_ltime count);
void	thrd_delete(t_thrd **list);

/**** TOOLS ****/

int		w_atoi(const char *nptr);
t_ltime	get_time(void);
void	*wati_sleep(t_philo *philo, t_ltime nb);

void	set_pvar(t_pvar *var, t_ltime value);
void	set_incr(t_pvar *var);
void	*m_print(t_philo *philo, char *format);

#endif // PHILO_H