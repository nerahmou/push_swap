/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 14:52:42 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:21:32 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reverse(t_queue *queue)
{
	t_elem *head;
	t_elem *tmp;
	t_elem *last;

	if (!queue->first || ft_lstlen(queue) < 2)
		return (0);
	head = queue->first;
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	queue->first = last;
	return (0);
}

int	rotate(t_queue *queue)
{
	t_elem *tmp;
	t_elem *head;

	if (!queue->first || ft_lstlen(queue) < 2)
		return (0);
	tmp = queue->first;
	head = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	queue->first->next = NULL;
	tmp->next = queue->first;
	queue->first = head;
	return (0);
}
