/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:04:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/21 15:34:50 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	sort_three(t_queue *queue)
{
	int total1;
	int total2;

	total1 = queue->first->next->nbr - queue->first->nbr;
	total2 = queue->first->next->nbr - queue->first->next->next->nbr;
	if (total1 < 0 && total2 < 0)
		total1 > total2 ? ft_printf("sa\n", swap(queue)) :
			ft_printf("ra\n", rotate(queue));
	else if (total1 > 0 && total2 > 0)
		total1 > total2 ? ft_printf("rra\nsa\n", reverse(queue),
				swap(queue)) : ft_printf("rra\n", reverse(queue));
	else if (total1 < total2)
		ft_printf("sa\nrra\n", swap(queue), reverse(queue));
	return (1);
}

static	int	sort(t_queue *queue_a, t_queue *queue_b)
{
	if (check_sort(queue_a, 0))
		return (1);
	if (queue_a->len == 2)
		return (ft_printf("sa\n", swap(queue_a)));
	if (queue_a->len == 3)
		return (sort_three(queue_a));
	easy_sort(queue_a, queue_b);
	while (queue_b->first)
	{
		ft_printf("pa\n", push(queue_a, queue_b));
		if (!check_sort(queue_a, 0))
			easy_sort(queue_a, queue_b);
	}
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
			sort(s_c.queue_a, s_c.queue_b);
			queue_clr(&s_c.queue_b);
		}
		queue_clr(&s_c.queue_a);
	}
	return (0);
}
