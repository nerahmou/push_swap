/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easy_sort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:02:31 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:34:13 by nerahmou    ###    #+. /#+    ###.fr     */
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

static void	ft_apply(t_queue *queue_a, int op)
{
	if (op == NEXT_LAST)
	{
		if (get(queue_a, 'n')->nbr < get(queue_a, 'l')->nbr)
			ft_printf("ra\n", rotate(queue_a));
		else
			ft_printf("sa\nrra\n", swap(queue_a), reverse(queue_a));
	}
	else if (op == NEXT)
		ft_printf("sa\n", swap(queue_a));
	else
		ft_printf("rra\n", reverse(queue_a));
}

int			easy_sort(t_queue *queue_a, t_queue *queue_b)
{
	t_fnlp fnlp;

	while (!check_sort(queue_a, 0))
	{
		fnlp.first = queue_a->first->nbr;
		fnlp.next = get(queue_a, 'n')->nbr;
		fnlp.last = get(queue_a, 'l')->nbr;
		if (ft_lstlen(queue_a) == 3)
			sort_three(queue_a);
		else if (fnlp.next != fnlp.last && fnlp.first > fnlp.next
				&& fnlp.first > fnlp.last)
			ft_apply(queue_a, NEXT_LAST);
		else if (fnlp.first > fnlp.next)
			ft_apply(queue_a, NEXT);
		else if (fnlp.first > fnlp.last)
			ft_apply(queue_a, LAST);
		else
			ultime_sort(queue_a, queue_b);
	}
	while (queue_b->first)
		ft_printf("pa\n", push(queue_a, queue_b));
	return (1);
}
