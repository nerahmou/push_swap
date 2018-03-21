/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easy_sort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:02:31 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/21 14:28:09 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	double_op(t_queue *queue, int op)
{
	int	first;
	int	next;
	int	last;

	first = queue->first->nbr;
	next = get(queue, 'n');
	last = get(queue, 'l');
	if (op == NEXT && next != last && ((first < next && last < first) ||
				(first < next && first < last && next < last)))
		return (1);
	if (op == LAST && ((first < last && last < next) ||
				(first < last && next < first)))
		return (1);
	if (op == NEXT_LAST && first < next && first < last && next > last)
		return (1);
	if (first < next && first < last && next < last)
		return (1);
	return (0);
}

static void	ft_next(t_queue *queue_a, t_queue *queue_b)
{
	if (ft_lstlen(queue_b) > 1 && double_op(queue_b, NEXT))
		ft_printf("ss\n", swap(queue_a), swap(queue_b));
	else
		ft_printf("sa\n", swap(queue_a));
}

static void	ft_last(t_queue *queue_a, t_queue *queue_b)
{
	if (ft_lstlen(queue_b) > 2 && double_op(queue_b, LAST))
		ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
	else
		ft_printf("rra\n", reverse(queue_a));
}

static void	ft_next_last(t_queue *queue_a, t_queue *queue_b, t_fnlp fnlp)
{
	if (fnlp.next < fnlp.last)
	{
		if (ft_lstlen(queue_b) > 2 && double_op(queue_b, NEXT_LAST))
			ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
		else
			ft_printf("ra\n", rotate(queue_a));
	}
	else
	{
		if (ft_lstlen(queue_b) > 2 && double_op(queue_b, 0))
			ft_printf("ss\nrrr\n", swap(queue_a), reverse(queue_a),
					swap(queue_b), reverse(queue_b));
		else
			ft_printf("sa\nrra\n", swap(queue_a), reverse(queue_a));
	}
}

int			easy_sort(t_queue *queue_a, t_queue *queue_b)
{
	t_fnlp fnlp;

	if (ft_lstlen(queue_a) > 1)
		while (!check_sort(queue_a, 0))
		{
			fnlp.first = queue_a->first->nbr;
			fnlp.next = get(queue_a, 'n');
			fnlp.last = get(queue_a, 'l');
			if (fnlp.next != fnlp.last && fnlp.first > fnlp.next
					&& fnlp.first > fnlp.last)
				ft_next_last(queue_a, queue_b, fnlp);
			else if (fnlp.first > fnlp.next)
				ft_next(queue_a, queue_b);
			else if (fnlp.first > fnlp.last)
				ft_last(queue_a, queue_b);
			else
			{
				ft_printf("pb\n", push(queue_b, queue_a));
				easy_sort_b(queue_a, queue_b);
			}
		}
	return (1);
}
