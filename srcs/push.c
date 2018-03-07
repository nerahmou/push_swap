/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 15:42:28 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 08:24:19 by nerahmou    ###    #+. /#+    ###.fr     */
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
