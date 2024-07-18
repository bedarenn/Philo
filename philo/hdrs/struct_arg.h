/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:35:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:51:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ARG_H
# define STRUCT_ARG_H

# include "w_struct.h"

typedef struct s_global
{
	t_mutex	m_end;
	bool	end;
	t_mutex	m_print;
	t_ltime	start;
}	t_global;

typedef struct s_arg
{
	t_ltime		dietime;
	t_ltime		eattime;
	t_ltime		sleeptime;
	t_ltime		eatend;
	t_global	var;
}	t_arg;

#endif // STRUCT_ARG_H