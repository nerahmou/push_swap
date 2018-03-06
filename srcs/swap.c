/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 15:44:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:21:59 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_queue *queue)
{
	t_elem *elem;

	elem = queue->first;
	if (ft_lstlen(queue) < 2)
		return (0);
	ft_swap(&elem->nbr, &elem->next->nbr);
	return (1);
}
