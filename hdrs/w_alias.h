/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_alias.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:44:48 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/04 17:10:25 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_ALIAS_H
# define W_ALIAS_H

# include <stddef.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef long int		t_ltime;
typedef struct timeval	t_tv;

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthrd;

# define MS 1000
# define S_US 1000000

#endif // W_ALIAS_H