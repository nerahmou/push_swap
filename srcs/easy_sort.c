/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easy_sort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:02:31 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 20:42:17 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ultime_sort(t_queue *queue_a, t_queue *queue_b)
{
	int	pos_a;
	int	pos_b;

	if ((pos_a = check_pos(queue_a, 0)))
	{
		pos_b = check_pos_rev(queue_a, 0);
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
	if (!check_sort(queue_a))
		ft_printf("pb\n", push(queue_b, queue_a));
}

int			easy_sort(t_queue *queue_a, t_queue *queue_b)
{
	t_fnl fnl;

	while (!check_sort(queue_a))
	{
		fnl.first = queue_a->first->nbr;
		fnl.next = get(queue_a, 1)->nbr;
		fnl.last = get(queue_a, ft_lstlen(queue_a) - 1)->nbr;
		if (fnl.first > fnl.last)
			ft_printf("ra\n", rotate(queue_a));
		else if (fnl.first > fnl.next)
			ft_printf("sa\n", swap(queue_a));
		else
			ultime_sort(queue_a, queue_b);
	}
	while (queue_b->first)
		ft_printf("pa\n", push(queue_a, queue_b));
	return (1);
}
