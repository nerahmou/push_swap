/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operations.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:44:38 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 21:44:39 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_queue *dest, t_queue *src)
{
	t_elem *new;

	if (!dest || !src || ft_lstlen(src) < 1)
		return (0);
	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->nbr = src->first->nbr;
	new->next = NULL;
	if (dest->first)
	{
		new->next = dest->first;
		dest->first = new;
	}
	else
		dest->first = new;
	process(src);
	return (0);
}

int	swap(t_queue *queue)
{
	t_elem *elem;

	if (ft_lstlen(queue) < 2)
		return (0);
	elem = queue->first;
	ft_swap(&elem->nbr, &elem->next->nbr);
	return (1);
}

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
