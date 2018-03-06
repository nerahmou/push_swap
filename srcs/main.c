/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:47:59 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, const char *argv[])
{
	t_queues	s_c;

	s_c.queue_a = NULL;
	if (argc > 1)
	{
		if (!parse_param(++argv, &(s_c.queue_a)))
			ft_printf("{bold}Error\n{eoc}");
		else
		{
			s_c.queue_a->name = 'A';
			display_queue(s_c.queue_a);
			s_c.queue_b = init();
			s_c.queue_b->name = 'B';
			while (get_next_line(0, &(s_c.operation)))
			{
				push_swap(s_c);
				display_queue(s_c.queue_a);
				display_queue(s_c.queue_b);
			}
		}
	}
	return (0);
}
