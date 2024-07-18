/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/18 17:35:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

int			main(int argc, char **argv);

static int	w_error(void);

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_ltime	count;
	t_thrd	*list;

	if (argc != 5 && argc != 6)
		return (w_error());
	count = w_atoi(argv[1]);
	if (count <= 0 || !init_arg(&arg, argc, argv))
		return (w_error());
	list = thrd_create(count, &arg);
	arg.var.start = get_time();
	thrd_laucher(list);
	usleep(MS);
	thrd_join(list, count);
	thrd_delete(&list);
	return (0);
}

int	w_error(void)
{
	printf("Error\n");
	return (1);
}
