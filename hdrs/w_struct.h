/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:42 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 14:58:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_H
# define W_STRUCT_H

# include <w_alias.h>

typedef struct s_global
{
	t_mutex	m_end;
	bool	end;
	t_mutex	m_print;
	t_tv	start;
}	t_global;

typedef struct s_arg
{
	t_ltime		dietime;
	t_ltime		eattime;
	t_ltime		sleeptime;
	t_ltime		eatend;
	t_global	var;
}	t_arg;

typedef struct s_fork
{
	t_mutex	left;
	t_mutex	*right;
}	t_fork;

typedef struct s_philo
{
	t_arg	*rules;
	t_fork	cutlery;
	size_t	id;
	t_tv	meal;
	t_ltime	i;
}	t_philo;

typedef struct s_thrd
{
	t_pthrd			pthread;
	t_philo			philo;
	struct s_thrd	*next;
}	t_thrd;

#endif // W_STRUCT_H
