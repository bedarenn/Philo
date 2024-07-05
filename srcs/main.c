/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/05 14:58:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

int	w_error(void)
{
	printf("Error\n");
	return (1);
}

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
	list = create_philos(count, &arg);
	gettimeofday(&arg.var.start, NULL);
	list_map(list, lauch_thrd);
	clear_thrd(&list);
	return (0);
}
