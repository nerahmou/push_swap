/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 14:56:48 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:59:17 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_stack *stack)
{
	size_t length;
	t_elem *tmp;

	length = 0;
	tmp = stack->first;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}
