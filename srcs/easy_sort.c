/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easy_sort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:02:31 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 23:10:29 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	sign(int pile_a, int nbr1, int nbr2)
{
	if (pile_a)
	{
		if (nbr1 > nbr2)
			return (1);
	}
	else if (nbr1 < nbr2)
		return (1);
	return (0);
}

static int	double_op(t_queue *queue, int pile_a, int op)
{
	pile_a = pile_a ? 0 : pile_a;
	if (op == NEXT &&
			((sign(pile_a, queue->first->nbr, get(queue, 'n')) &&
			sign(pile_a, get(queue, 'l'), queue->first->nbr)) ||
			(sign(pile_a, queue->first->nbr, get(queue, 'n')) &&
			sign(pile_a, queue->first->nbr, get(queue, 'l')) &&
			sign(pile_a, get(queue, 'n'), get(queue, 'l')))))
		return (1);
	if (op == LAST &&
			sign(pile_a, queue->first->nbr, get(queue, 'l')) &&
			sign(pile_a, get(queue, 'l'), get(queue, 'n')))
		return (1);
	if (op == NEXT_LAST &&
			sign(pile_a, queue->first->nbr, get(queue, 'n')) &&
			sign(pile_a, queue->first->nbr, get(queue, 'l')))
		return (1);
	if (sign(pile_a, queue->first->nbr, get(queue, 'n')) &&
			sign(pile_a, queue->first->nbr, get(queue, 'l')) &&
			sign(pile_a, get(queue, 'n'), get(queue, 'l')))
		return (1);
	return (0);
}

static void	ft_next(t_queue *queue_a, t_queue *queue_b, int pile_a)
{
	if (ft_lstlen(queue_b) > 1 && double_op(queue_b, pile_a, NEXT))
		ft_printf("ss\n", swap(queue_a), swap(queue_b));
	else
		ft_printf(pile_a ? "sa\n" : "sb\n", swap(queue_a));
}

static void	ft_last(t_queue *queue_a, t_queue *queue_b, int pile_a)
{
	if (ft_lstlen(queue_b) > 1 && double_op(queue_b, pile_a, LAST))
		ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
	else
	{
		if (check_last_low(queue_a, get(queue_a, 'l'), pile_a ? 0 : 1))
			ft_printf(pile_a ? "rra\n" : "rrb\n", reverse(queue_a));
		else
			ft_printf(pile_a ? "ra\n" : "rb\n", rotate(queue_a));
	}
}

static void	ft_next_last(t_queue *queue_a, t_queue *queue_b, t_fnlp fnlp)
{
	if (sign(fnlp.pile_a ? 0 : 1, fnlp.next, fnlp.last))
	{
		if (ft_lstlen(queue_b) > 2 &&
				double_op(queue_b, fnlp.pile_a, NEXT_LAST))
			ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
		else
			ft_printf(fnlp.pile_a ? "ra\n" : "rb\n", rotate(queue_a));
	}
	else
	{
		if (ft_lstlen(queue_b) > 2 && double_op(queue_b, fnlp.pile_a, 0))
			ft_printf("ss\nrrr\n", swap(queue_a), reverse(queue_a),
					swap(queue_b), reverse(queue_b));
		else
			ft_printf(fnlp.pile_a ? "sa\nrra\n" : "sb\nrrb\n",
					swap(queue_a), reverse(queue_a));
	}
}

int			easy_sort(t_queue *queue_a, t_queue *queue_b, int pile_a)
{
	t_fnlp fnlp;

	fnlp.pile_a = pile_a;
	if (ft_lstlen(queue_a) > 1)
		while (!check_sort(queue_a, pile_a ? 0 : 1))
		{
			fnlp.first = queue_a->first->nbr;
			fnlp.next = get(queue_a, 'n');
			fnlp.last = get(queue_a, 'l');
			if (fnlp.next != fnlp.last && sign(pile_a, fnlp.first, fnlp.next)
					&& sign(pile_a, fnlp.first, fnlp.last))
				ft_next_last(queue_a, queue_b, fnlp);
			else if (sign(pile_a, fnlp.first, fnlp.next))
				ft_next(queue_a, queue_b, fnlp.pile_a);
			else if (sign(pile_a, fnlp.first, fnlp.last))
				ft_last(queue_a, queue_b, fnlp.pile_a);
			else if (pile_a)
			{
				ft_printf("pb\n", push(queue_b, queue_a));
				easy_sort(queue_b, queue_a, 0);
			}
			else
				break ;
		}
	return (1);
}
