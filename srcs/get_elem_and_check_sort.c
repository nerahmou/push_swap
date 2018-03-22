/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_n_checklist.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:44:00 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:35:02 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_pos(t_queue *queue)
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
		if (min > tmp->nbr)
		{
			pos = i;
			min = tmp->nbr;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int		check_pos_rev(t_queue *queue)
{
	t_elem	*tmp;
	int		pos;
	int		i;
	int		min;

	i = 0;
	pos = 0;
	tmp = get(queue, 'l');
	min = queue->first->nbr;
	while (tmp)
	{
		if (min > tmp->nbr)
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

t_elem	*get(t_queue *queue, char c)
{
	t_elem	*tmp;

	tmp = queue->first;
	if (c == 'n')
		return (tmp->next);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
