/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easy_sort_b.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/21 12:44:36 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/21 17:05:38 by nerahmou    ###    #+. /#+    ###.fr     */
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
	if (op == NEXT && next != last && ((first > next && last > first) ||
				(first > next && first > last && next > last)))
		return (1);
	if (op == LAST && ((first > last && last > next) ||
				(first > last && next > first)))
		return (1);
	if (op == NEXT_LAST && first > next && first > last && next < last)
		return (1);
	if (first > next && first > last && next > last)
		return (1);
	return (0);
}

static void	ft_next(t_queue *queue_a, t_queue *queue_b)
{
	if (ft_lstlen(queue_a) > 1 && double_op(queue_a, NEXT))
		ft_printf("ss\n", swap(queue_a), swap(queue_b));
	else
		ft_printf("sb\n", swap(queue_b));
}

static void	ft_last(t_queue *queue_a, t_queue *queue_b)
{
	if (ft_lstlen(queue_a) > 2 && double_op(queue_a, LAST))
		ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
	else
		ft_printf("rrb\n", reverse(queue_b));
}

static void	ft_next_last(t_queue *queue_a, t_queue *queue_b, t_fnlp fnlp)
{
	if (fnlp.next < fnlp.last)
	{
		if (ft_lstlen(queue_a) > 2 && double_op(queue_a, NEXT_LAST))
			ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
		else
			ft_printf("rb\n", rotate(queue_b));
	}
	else
	{
		if (ft_lstlen(queue_a) > 2 && double_op(queue_a, 0))
			ft_printf("ss\nrrr\n", swap(queue_a), reverse(queue_a),
					swap(queue_b), reverse(queue_b));
		else
			ft_printf("sb\nrrb\n", swap(queue_b), reverse(queue_b));
	}
}

int			easy_sort_b(t_queue *queue_a, t_queue *queue_b)
{
	t_fnlp fnlp;

	if (ft_lstlen(queue_b) > 1)
		while (!check_sort(queue_b, 1))
		{
			fnlp.first = queue_b->first->nbr;
			fnlp.next = get(queue_b, 'n');
			fnlp.last = get(queue_b, 'l');
			if (fnlp.next != fnlp.last &&
					fnlp.first < fnlp.next &&
					fnlp.first < fnlp.last)
				ft_next_last(queue_a, queue_b, fnlp);
			else if (fnlp.first < fnlp.next)
				ft_next(queue_a, queue_b);
			else if (fnlp.first < fnlp.last)
				ft_last(queue_a, queue_b);
			else
				break ;
		}
	return (1);
}
