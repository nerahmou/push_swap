/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   medium_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 12:10:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 17:05:20 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
static void	ultime_sort(t_queue *queue_a, t_queue *queue_b)
{
	int	pos_a;
	int	pos_b;

	if ((pos_a = check_pos(queue_a)))
	{
		pos_b = check_pos_rev(queue_a);
		if (pos_b + 1 < pos_a)
		{
			pos_b += 1;
			while (pos_b--)
				ft_printf("rra\n", reverse(queue_a));
		}
		else
			while (pos_a--)
				ft_printf("ra\n", rotate(queue_a));
	}
	if (!check_sort(queue_a, 0))
		ft_printf("pb\n", push(queue_b, queue_a));
}

static void	double_op(t_queue *queue_a, t_queue *queue_b, int op)
{
	if (op == last)
	{
		if (queue_b->first->nbr < get(queue_b, ft_lstlen(queue_b) - 1, 0)->nbr)
			ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
		else
			ft_printf("ra\n", rotate(queue_a));
	}
	else
	{
		if (queue_b->first->nbr < get(queue_b, 1, 0)->nbr)
			ft_printf("ss\n", swap(queue_a), swap(queue_b));
		else
			ft_printf("sa\n", swap(queue_a));
	}
}
*/
int	medium_sort(t_queue *queue_a, t_queue *queue_b)
{
	partition(queue_a, queue_b);
/*	while (!check_sort(queue_a, 0))
	{
		fnlp.first = queue_a->first->nbr;
		fnlp.next = get(queue_a, 1, 0)->nbr;
		fnlp.last = get(queue_a, ft_lstlen(queue_a) - 1, 0)->nbr;
		if (fnlp.first > fnlp.last)
			double_op(queue_a, queue_b, last);
		else if (fnlp.first > fnlp.next)
			double_op(queue_a, queue_b, next);
		else
			ultime_sort(queue_a, queue_b);
	}
	while (queue_b->first)
		ft_printf("pa\n", push(queue_a, queue_b));
*/	return (1);
}
