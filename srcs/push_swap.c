/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:04:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 19:05:05 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	sort_three(t_queue *queue)
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
}

static	int		easy_sort(t_queue *queue_a, t_queue *queue_b)
{
	if (queue_a->len == 2)
	{
		if (queue_a->first->nbr > queue_a->first->next->nbr)
			swap(queue_a);
	}
	else if (queue_a->len == 3)
		sort_three(queue_a);
	if (queue_b)
		;
	return (1);
}

int				main(int argc, const char *argv[])
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
			easy_sort(s_c.queue_a, s_c.queue_b);
			queue_clr(&s_c.queue_b);
		}
		queue_clr(&s_c.queue_a);
	}
	return (0);
}
