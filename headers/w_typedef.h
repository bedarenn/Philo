/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_typedef.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:56:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:40:25 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_TYPEDEF_H
# define W_TYPEDEF_H

# include <stddef.h>
# include <sys/time.h>
# include <pthread.h>

typedef long int		t_ltime;
typedef struct timeval	t_tv;

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthrd;

typedef enum s_bool
{
	ERROR = -1,
	FALSE,
	TRUE,
}	t_bool;

#endif