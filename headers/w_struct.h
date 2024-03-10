/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:58:11 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/09 13:14:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_H
# define W_STRUCT_H

# include <w_typedef.h>

typedef struct s_arg
{
	t_ltime	dietime;
	t_ltime	eattime;
	t_ltime	sleeptime;
	t_ltime	eatend;
	t_mutex	m_end;
	t_bool	end;
	t_mutex	m_print;
	t_tv	start;
}	t_arg;

typedef struct s_fork
{
	t_mutex	*left;
	t_mutex	right;
}	t_fork;

typedef struct s_philo
{
	t_arg	*arg;
	t_fork	fork;
	size_t	id;
}	t_philo;

typedef struct s_thrd
{
	t_pthrd			pthread;
	t_philo			philo;
	struct s_thrd	*next;
}	t_thrd;

typedef struct t_meal
{
	t_tv	actual;
	t_tv	last;
}	t_meal;

#endif