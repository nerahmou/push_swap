/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 12:46:46 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static  int free_all(t_queues s_c)
{
		queue_clr(&s_c.queue_a);
		queue_clr(&s_c.queue_b);
		ft_strdel(&s_c.operation);
		exit(EXIT_SUCCESS);
}

static int	check_result(t_queue *queue_a, t_queue *queue_b)
{
	t_elem *tmp;

	if (ft_lstlen(queue_b))
		return (0);
	tmp = queue_a->first;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			main(int argc, const char *argv[])
{
	t_queues	s_c;

	if (argc > 1)
	{
		if (!parse_param(++argv, &(s_c.queue_a)))
			ft_printf("{bold}{red}Error\n{eoc}");
		else
		{
			s_c.queue_a->name = 'A';
			s_c.queue_b = init();
			s_c.queue_b->name = 'B';
			display_queue(s_c.queue_a);
			display_queue(s_c.queue_b);
			while (get_next_line(0, &s_c.operation))
			{
				if (!operations(s_c))
					free_all(s_c);
				ft_strdel(&s_c.operation);
				display_queue(s_c.queue_a);
				display_queue(s_c.queue_b);
			}
			if (check_result(s_c.queue_a, s_c.queue_b))
				ft_printf("{green}{bold}OK{eoc}\n");
			else
				ft_printf("{red}{bold}KO{eoc}\n");
		}
		free_all(s_c);
	}
	return (0);
}
