/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   medium_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 12:10:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 20:41:49 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ultime_sort(t_queue *queue_a, t_queue *queue_b)
{
	int	pos_a;
	int	pos_b;
	int swp;

	swp = 0;
	if ((pos_a = check_pos(queue_b, 1)))
	{
		pos_b = check_pos_rev(queue_b, 1);
		if (pos_b < pos_a)
		{
			pos_b += 1;
			while (pos_b--)
				ft_printf("rrb\n", reverse(queue_b));
		}
		else
		{
			if (pos_a)
				swp = 1;
			while (pos_a-- > 1)
				ft_printf("rb\n", rotate(queue_b));
			if (swp)
				ft_printf("sb\n", swap(queue_b));
		}
	}
	ft_printf("pa\n", push(queue_a, queue_b));
}

int			big_sort(t_queue *queue_a, t_queue *queue_b)
{
	if (ft_lstlen(queue_a) > 200)
		while (ft_lstlen(queue_a) > 2)
			partition_big(queue_a, queue_b);
	else
		while (ft_lstlen(queue_a) > 2)
			partition_med(queue_a, queue_b);
	if (!check_sort(queue_a))
		ft_printf("sa\n", swap(queue_a));
	while (ft_lstlen(queue_b))
		ultime_sort(queue_a, queue_b);
	return (1);
}
