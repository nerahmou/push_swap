/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_check.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 16:04:08 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 18:18:14 by nerahmou    ###    #+. /#+    ###.fr     */
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

t_elem	*get_next(t_queue *queue)
{
	return (queue->first->next);
}

t_elem	*get_last(t_queue *queue)
{
	t_elem	*tmp;

	tmp = queue->first;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
