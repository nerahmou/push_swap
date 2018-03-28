/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   medium_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 12:10:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 14:22:27 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	found_less(t_queue *queue_b, int pivot)
{
	t_elem *tmp;

	tmp = queue_b->first;
	while (tmp)
	{
		if (tmp->nbr > pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static	void	part(t_queue *queue_a, t_queue *queue_b, int pos, int rev)
{
	t_elem *tmp;
	
	if (!rev)
	{
		tmp = queue_b->first;
		while (pos--)
			ft_printf("rb\n", rotate(queue_b));
	}
	else
	{
		tmp = get(queue_b, ft_lstlen(queue_b) - 1, 0);
		while (pos--)
			ft_printf("rrb\n", reverse(queue_b));
	}
	ft_printf("pa\n", push(queue_a, queue_b));
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
			if (tmp->nbr > nbr)
				i++;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (nbr);
}

static void	partition_b(t_queue *queue_a, t_queue *queue_b, int rev)
{
	t_elem *tmp;
	int		pos_a;
	int		pos_b;
	int		pivot;

	tmp = queue_b->first;
	pivot = get_pivot(queue_b);
	while (found_less(queue_b, pivot))
	{
		pos_a = check_low(queue_b, pivot, 0, rev);
		pos_b = check_low(queue_b, pivot, 1, rev);
		if ((pos_a == pos_b &&
				get(queue_a, pos_a, 0)->nbr > get(queue_a, pos_b - 1, 1)->nbr)
				|| pos_a < pos_b)
			part(queue_a, queue_b, pos_a, 0);
		else
			part(queue_a, queue_b, pos_b, 1);
	}
}


static void	ultime_sort(t_queue *queue_a, t_queue *queue_b)
{
	int	pos_a;
	int	pos_b;

	if ((pos_a = check_pos(queue_b, 1)))
	{
		pos_b = check_pos_rev(queue_b, 1);
		if (pos_b  < pos_a)
		{
			pos_b += 1;
			while (pos_b--)
				ft_printf("rrb\n", reverse(queue_b));
		}
		else
		{
			while (pos_a--)
				ft_printf("rb\n", rotate(queue_b));
		}
	}
	ft_printf("pa\n", push(queue_a, queue_b));
}

int	medium_sort(t_queue *queue_a, t_queue *queue_b)
{
	while (ft_lstlen(queue_a) > 4)
		partition(queue_a, queue_b, 0);
	while (ft_lstlen(queue_b))
		ultime_sort(queue_a, queue_b);
	return (1);



/*	while (ft_lstlen(queue_a) > 4)
		partition(queue_a, queue_b, 0);
	if (queue_a->first->nbr > get(queue_a, 1 , 0)->nbr)
		ft_printf("sa\n", swap(queue_a));
	while (ft_lstlen(queue_b))
		ultime_sort(queue_a, queue_b);
	return (1);
*/
	}

/* tri 4/ 5 pour les 500
int	medium_sort(t_queue *queue_a, t_queue *queue_b)
{
//	while (ft_lstlen(queue_a) > 5)
//		partition(queue_a, queue_b, 0);
//	while (ft_lstlen(queue_b) > 5)
//		partition_b(queue_a, queue_b, 1);
	while (ft_lstlen(queue_a) > ft_lstlen(queue_b))
		partition(queue_a, queue_b, 0);
	while (ft_lstlen(queue_b) > 4)
		partition_b(queue_a, queue_b, 1);
	if (queue_a->first->nbr > get(queue_a, 1 , 0)->nbr)
		ft_printf("sa\n", swap(queue_a));
	while (ft_lstlen(queue_a) > 4)
		partition(queue_a, queue_b, 0);
	while (ft_lstlen(queue_b))
		ultime_sort(queue_a, queue_b);
	return (1);
}
*/
