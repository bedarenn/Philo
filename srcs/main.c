/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:24 by bedarenn          #+#    #+#             */
/*   Updated: 2024/03/09 13:15:05 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_thrd	*philos;
	int		count;
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (1);
	count = w_atoi(argv[1]);
	arg = set_arg(argc, argv + 2);
	if (!check_arg(count, arg))
		return (1);
	philos = create_philos(count, &arg);
	if (!philos)
		return (1);
	arg.end = 0;
	pthread_mutex_init(&arg.m_end, NULL);
	pthread_mutex_init(&arg.m_print, NULL);
	gettimeofday(&arg.start, NULL);
	if (argc == 5)
		list_map(philos, &lauch_thrd);
	else
		list_map(philos, &lauch_thrd_time);
	list_map(philos, &wait_thrd);
	free_philos(philos);
	return (0);
}
