/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_n_checklist.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:44:00 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 15:20:53 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_low(t_queue *queue, int pivot, int rev, int high)
{
	t_elem *tmp;
	int		pos;

	pos = 0;
	if (!rev)
	{
		tmp = queue->first;
		while (!high ? tmp->nbr >= pivot : pivot > tmp->nbr)
		{
			pos++;
			tmp = tmp->next;
		}
	}
	else
	{
		pos++;
		tmp = get(queue, ft_lstlen(queue) - 1, 0);
		while (!high ? tmp->nbr >= pivot : pivot > tmp->nbr)
		{
			pos++;
			tmp = tmp->prev;
		}
	}
	return (pos);
}


int		check_pos(t_queue *queue, int rev)
{
	t_elem	*tmp;
	int		pos;
	int		i;
	int		min;

	i = 0;
	pos = 0;
	tmp = queue->first;
	min = tmp->nbr;
	while (tmp)
	{
		if (!rev ? (min > tmp->nbr) : (tmp->nbr > min))
		{
			pos = i;
			min = tmp->nbr;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int		check_pos_rev(t_queue *queue, int rev)
{
	t_elem	*tmp;
	int		pos;
	int		i;
	int		min;

	i = 0;
	pos = 0;
	tmp = get(queue, ft_lstlen(queue) - 1, 0);
	min = queue->first->nbr;
	while (tmp)
	{
		if (!rev ? (min > tmp->nbr) : (tmp->nbr > min))
		{
			pos = i;
			min = tmp->nbr;
		}
		i++;
		tmp = tmp->prev;
	}
	return (pos);
}

int		check_sort(t_queue *queue, int rev)
{
	t_elem *tmp;

	tmp = queue->first;
	if (!rev)
		while (tmp->next)
		{
			if (tmp->nbr > tmp->next->nbr)
				return (0);
			tmp = tmp->next;
		}
	else
		while (tmp->next)
		{
			if (tmp->nbr < tmp->next->nbr)
				return (0);
			tmp = tmp->next;
		}
	return (1);
}

t_elem	*get(t_queue *queue, int i, int rev)
{
	t_elem	*tmp;

	tmp = queue->first;
	if (!rev)
		while (i--)
			tmp = tmp->next;
	else
	{
		tmp = get(queue, ft_lstlen(queue) - 1, 0);
		while (i--)
			tmp = tmp->prev;
	}
	return (tmp);
}
