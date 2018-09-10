/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operations.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:44:38 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:33 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_stack *dest, t_stack *src)
{
	t_elem *new;

	if (!dest || !src || ft_lstlen(src) < 1)
		return (0);
	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->nbr = src->first->nbr;
	new->next = NULL;
	new->prev = NULL;
	if (dest->first)
	{
		new->next = dest->first;
		dest->first->prev = new;
		dest->first = new;
	}
	else
		dest->first = new;
	process(src);
	return (0);
}

int	swap(t_stack *stack)
{
	t_elem *elem;

	if (ft_lstlen(stack) < 2)
		return (0);
	elem = stack->first;
	ft_swap(&elem->nbr, &elem->next->nbr);
	return (1);
}

int	reverse(t_stack *stack)
{
	t_elem *head;
	t_elem *tmp;
	t_elem *last;

	if (!stack->first || ft_lstlen(stack) < 2)
		return (0);
	head = stack->first;
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	last->prev = NULL;
	head->prev = last;
	stack->first = last;
	return (0);
}

int	rotate(t_stack *stack)
{
	t_elem *tmp;
	t_elem *head;

	if (!stack->first || ft_lstlen(stack) < 2)
		return (0);
	tmp = stack->first;
	head = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	stack->first->next = NULL;
	tmp->next = stack->first;
	stack->first->prev = tmp;
	head->prev = NULL;
	stack->first = head;
	return (0);
}
