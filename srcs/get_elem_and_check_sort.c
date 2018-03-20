/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_n_checklist.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:44:00 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 23:11:10 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int		check_last_low(t_queue *queue, int last, int rev)
{
	t_elem *tmp;

	tmp = queue->first;
	if (!rev)
		while (tmp->next)
		{
			if (tmp->nbr < last)
				return (0);
			tmp = tmp->next;
		}
	else
	{
		tmp = tmp->next;
		while (tmp)
		{
			if (last > tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		get(t_queue *queue, char c)
{
	t_elem	*tmp;

	tmp = queue->first;
	if (c == 'n')
		return (tmp->next->nbr);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->nbr);
}
