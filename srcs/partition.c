/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   partition.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 15:37:48 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 20:40:30 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	found_less(t_queue *queue_a, int pivot)
{
	t_elem *tmp;

	tmp = queue_a->first;
	while (tmp)
	{
		if (tmp->nbr < pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	part(t_queue *queue_a, t_queue *queue_b, int pos, int rev)
{
	t_elem	*tmp;

	if (!rev)
	{
		tmp = queue_a->first;
		while (pos--)
		{
			if (ft_lstlen(queue_b) > 1 &&
					(queue_b->first->nbr >
					get(queue_b, ft_lstlen(queue_b) - 1)->nbr))
				ft_printf("rr\n", rotate(queue_a), rotate(queue_b));
			else
				ft_printf("ra\n", rotate(queue_a));
		}
	}
	else
	{
		tmp = get(queue_a, ft_lstlen(queue_a) - 1);
		while (pos--)
			ft_printf("rra\n", reverse(queue_a));
	}
	ft_printf("pb\n", push(queue_b, queue_a));
}

static int	get_pivot(t_queue *queue, int *div)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		middle;
	int		i;
	int		nbr;

	i = 0;
	tmp2 = queue->first;
	middle = ft_lstlen(queue) / (ft_lstlen(queue) < 50 &&
			*div > 2 ? (*div)-- : *div);
	while (i != middle)
	{
		i = 0;
		tmp = queue->first;
		nbr = tmp2->nbr;
		while (tmp)
		{
			if (tmp->nbr < nbr)
				i++;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (nbr);
}

void		partition_med(t_queue *queue_a, t_queue *queue_b)
{
	t_elem		*tmp;
	int			pos_a;
	int			pos_b;
	int			pivot;
	static int	div = 4;

	tmp = queue_a->first;
	pivot = get_pivot(queue_a, &div);
	while (found_less(queue_a, pivot))
	{
		pos_a = check_low(queue_a, pivot, 0);
		pos_b = check_low(queue_a, pivot, 1);
		if (pos_a < pos_b)
			part(queue_a, queue_b, pos_a, 0);
		else
			part(queue_a, queue_b, pos_b, 1);
		if (ft_lstlen(queue_b) > 1 &&
				(queue_b->first->nbr >
				get(queue_b, ft_lstlen(queue_b) - 1)->nbr))
			ft_printf("rb\n", rotate(queue_b));
	}
}

void		partition_big(t_queue *queue_a, t_queue *queue_b)
{
	t_elem		*tmp;
	int			pos_a;
	int			pos_b;
	int			pivot;
	static int	div = 7;

	tmp = queue_a->first;
	pivot = get_pivot(queue_a, &div);
	while (found_less(queue_a, pivot))
	{
		pos_a = check_low(queue_a, pivot, 0);
		pos_b = check_low(queue_a, pivot, 1);
		if (pos_a < pos_b)
			part(queue_a, queue_b, pos_a, 0);
		else
			part(queue_a, queue_b, pos_b, 1);
		if (ft_lstlen(queue_b) > 1 &&
				(queue_b->first->nbr >
				get(queue_b, ft_lstlen(queue_b) - 1)->nbr))
			ft_printf("rb\n", rotate(queue_b));
	}
}
