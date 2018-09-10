/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_n_checklist.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:44:00 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:30 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_low(t_stack *stack, int pivot, int rev)
{
	t_elem	*tmp;
	int		pos;

	pos = 0;
	if (!rev)
	{
		tmp = stack->first;
		while (tmp->nbr >= pivot)
		{
			pos++;
			tmp = tmp->next;
		}
	}
	else
	{
		pos++;
		tmp = get(stack, ft_lstlen(stack) - 1);
		while (tmp->nbr >= pivot)
		{
			pos++;
			tmp = tmp->prev;
		}
	}
	return (pos);
}

int		check_pos(t_stack *stack, int rev)
{
	t_elem	*tmp;
	int		pos;
	int		i;
	int		min;

	i = 0;
	pos = 0;
	tmp = stack->first;
	min = tmp->nbr;
	while (tmp)
	{
		if (!rev ? (min > tmp->nbr) : (tmp->nbr > min))
		{
			pos = i;
			min = tmp->nbr;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int		check_pos_rev(t_stack *stack, int rev)
{
	t_elem	*tmp;
	int		pos;
	int		i;
	int		min;

	i = 0;
	pos = 0;
	tmp = get(stack, ft_lstlen(stack) - 1);
	min = stack->first->nbr;
	while (tmp)
	{
		if (!rev ? (min > tmp->nbr) : (tmp->nbr > min))
		{
			pos = i;
			min = tmp->nbr;
		}
		i++;
		tmp = tmp->prev;
	}
	return (pos);
}

int		check_sort(t_stack *stack)
{
	t_elem *tmp;

	tmp = stack->first;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_elem	*get(t_stack *stack, int pos)
{
	t_elem	*tmp;

	tmp = stack->first;
	while (pos--)
		tmp = tmp->next;
	return (tmp);
}
