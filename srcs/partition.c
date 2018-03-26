/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   partition.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 15:37:48 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 16:23:01 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	part(t_queue *queue_a, t_queue *queue_b, int pos, int rev)
{
	t_elem *tmp;

	if (!rev)
	{
		tmp = queue_a->first;
		while (pos--)
			ft_printf("ra\n", rotate(queue_a));
	}
	else
	{
		tmp = get(queue_a, ft_lstlen(queue_a) - 1, 0);
		while (pos--)
			ft_printf("rra\n", reverse(queue_a));
	}
	ft_printf("pb\n", push(queue_b, queue_a));
}

static	int	check_low(t_queue *queue, int pivot, int rev)
{
	t_elem *tmp;
	int		pos;

	pos = 0;
	if (!rev)
	{
		tmp = queue->first;
		while (tmp->nbr >= pivot)
		{
			pos++;
			tmp = tmp->next;
		}
	}
	else
	{
		pos++;
		tmp = get(queue, ft_lstlen(queue) - 1, 0);
		while (tmp->nbr >= pivot)
		{
			pos++;
			tmp = tmp->prev;
		}
	}
	return (pos);
}

static int	get_pivot(t_queue *queue)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		middle;
	int		i;
	int		nbr;

	i = 0;
	tmp2 = queue->first;
	middle = ft_lstlen(queue) / 2;
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

void	partition(t_queue *queue_a, t_queue *queue_b)
{
	t_elem *tmp;
	int		pos_a;
	int		pos_b;
	int		pivot;

	tmp = queue_a->first;
	pivot = get_pivot(queue_a);
	while (ft_lstlen(queue_a) > ft_lstlen(queue_b) + 1)
	{
		pos_a = check_low(queue_a, pivot, 0);
		pos_b = check_low(queue_a, pivot, 1);
		if ((pos_a == pos_b &&
				get(queue_a, pos_a, 0)->nbr < get(queue_a, pos_b - 1, 1)->nbr)
				|| pos_a < pos_b)
			part(queue_a, queue_b, pos_a, 0);
		else
			part(queue_a, queue_b, pos_b, 1);
	}
	display_queue(queue_a, queue_b);
}
