/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 15:44:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 16:32:29 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_lstlen(t_queue *queue)
{
	size_t length;
	t_elem *tmp;


	length = 0;
	tmp = queue->first;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}


int	swap(t_queue *queue)
{
	t_elem *tmp;

	tmp = NULL;

	if (ft_lstlen(queue) < 2)
		return (0);
	tmp = queue->first;

}
