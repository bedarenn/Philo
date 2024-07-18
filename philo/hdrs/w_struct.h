/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:42 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 11:40:58 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_H
# define W_STRUCT_H

# include "w_alias.h"

typedef struct s_pvar
{
	t_mutex	mutex;
	t_ltime	var;
}	t_pvar;

#endif // W_STRUCT_H
