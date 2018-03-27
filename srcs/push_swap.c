/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:04:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 15:00:51 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int argc, const char *argv[])
{
	t_queue *queue_a;
	t_queue *queue_b;

	if (argc > 1)
	{
		if (!parse_param(++argv, &(queue_a)))
			ft_printf("{bold}{red}Error\n{eoc}");
		else
		{
			queue_a->name = 'A';
			queue_b = init();
			queue_b->name = 'B';
			if (check_sort(queue_a, 0))
				;
			else if (queue_a->len <= 10)
				easy_sort(queue_a, queue_b);
			else
				medium_sort(queue_a, queue_b);
			queue_clr(&queue_b);
		}
		queue_clr(&queue_a);
	}
	return (0);
}
