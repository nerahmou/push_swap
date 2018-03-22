/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:04:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:08:54 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	sort_type(t_queue *queue_a, t_queue *queue_b)
{
	if (check_sort(queue_a, 0))
		return (1);
	if (queue_a->len < 500)
		return (easy_sort(queue_a, queue_b));
	return (1);
}

int			main(int argc, const char *argv[])
{
	t_queues	s_c;

	s_c.operation = NULL;
	if (argc > 1)
	{
		if (!parse_param(++argv, &(s_c.queue_a)))
			ft_printf("{bold}{red}Error\n{eoc}");
		else
		{
			s_c.queue_a->name = 'A';
			s_c.queue_b = init();
			s_c.queue_b->name = 'B';
			sort_type(s_c.queue_a, s_c.queue_b);
			queue_clr(&s_c.queue_b);
		}
		queue_clr(&s_c.queue_a);
	}
	return (0);
}
