/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:35:22 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:51:16 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILO_H
# define STRUCT_PHILO_H

# include "struct_arg.h"

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
	t_pvar	meal;
	t_ltime	t;
	t_pvar	i;
}	t_philo;

typedef struct s_thrd
{
	t_pthrd			pthread;
	t_philo			philo;
	struct s_thrd	*next;
}	t_thrd;

#endif // STRUCT_PHILO_H