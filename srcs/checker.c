/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 12:31:12 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int argc, const char *argv[])
{
	t_queues	s_c;

	s_c.queue_a = NULL;
	s_c.queue_b = NULL;
	if (argc > 1)
	{
		if (!parse_param(++argv, &(s_c.queue_a)))
			ft_printf("{bold}{red}Error\n{eoc}");
		else
		{
			s_c.queue_a->name = 'A';
			s_c.queue_b = init();
			s_c.queue_b->name = 'B';
			while (get_next_line(0, &s_c.operation))
			{
				operations(s_c);
				ft_strdel(&s_c.operation);
				display_queue(s_c.queue_a);
				display_queue(s_c.queue_b);
				ft_printf("\n");
			}
			if (check_sort(s_c.queue_a, 0) && !ft_lstlen(s_c.queue_b))
				ft_printf("{green}{bold}OK{eoc}\n");
			else
				ft_printf("{red}{bold}KO{eoc}\n");
			queue_clr(&s_c.queue_b);
		}
		queue_clr(&s_c.queue_a);
	}
	return (0);
}
