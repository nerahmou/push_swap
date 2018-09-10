/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   partition.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 15:37:48 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:37 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	found_less(t_stack *stack_a, int pivot)
{
	t_elem *tmp;

	tmp = stack_a->first;
	while (tmp)
	{
		if (tmp->nbr < pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	part(t_stack *stack_a, t_stack *stack_b, int pos, int rev)
{
	t_elem	*tmp;

	if (!rev)
	{
		tmp = stack_a->first;
		while (pos--)
		{
			if (ft_lstlen(stack_b) > 1 &&
					(stack_b->first->nbr >
					get(stack_b, ft_lstlen(stack_b) - 1)->nbr))
				ft_printf("rr\n", rotate(stack_a), rotate(stack_b));
			else
				ft_printf("ra\n", rotate(stack_a));
		}
	}
	else
	{
		tmp = get(stack_a, ft_lstlen(stack_a) - 1);
		while (pos--)
			ft_printf("rra\n", reverse(stack_a));
	}
	ft_printf("pb\n", push(stack_b, stack_a));
}

static int	get_pivot(t_stack *stack, int *div)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		middle;
	int		i;
	int		nbr;

	i = 0;
	tmp2 = stack->first;
	middle = ft_lstlen(stack) / (ft_lstlen(stack) < 50 &&
			*div > 2 ? (*div)-- : *div);
	while (i != middle)
	{
		i = 0;
		tmp = stack->first;
		nbr = tmp2->nbr;
		while (tmp)
		{
			if (tmp->nbr < nbr)
				i++;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (nbr);
}

void		partition_med(t_stack *stack_a, t_stack *stack_b)
{
	t_elem		*tmp;
	int			pos_a;
	int			pos_b;
	int			pivot;
	static int	div = 4;

	tmp = stack_a->first;
	pivot = get_pivot(stack_a, &div);
	while (found_less(stack_a, pivot))
	{
		pos_a = check_low(stack_a, pivot, 0);
		pos_b = check_low(stack_a, pivot, 1);
		if (pos_a < pos_b)
			part(stack_a, stack_b, pos_a, 0);
		else
			part(stack_a, stack_b, pos_b, 1);
		if (ft_lstlen(stack_b) > 1 &&
				(stack_b->first->nbr >
				get(stack_b, ft_lstlen(stack_b) - 1)->nbr))
			ft_printf("rb\n", rotate(stack_b));
	}
}

void		partition_big(t_stack *stack_a, t_stack *stack_b)
{
	t_elem		*tmp;
	int			pos_a;
	int			pos_b;
	int			pivot;
	static int	div = 7;

	tmp = stack_a->first;
	pivot = get_pivot(stack_a, &div);
	while (found_less(stack_a, pivot))
	{
		pos_a = check_low(stack_a, pivot, 0);
		pos_b = check_low(stack_a, pivot, 1);
		if (pos_a < pos_b)
			part(stack_a, stack_b, pos_a, 0);
		else
			part(stack_a, stack_b, pos_b, 1);
		if (ft_lstlen(stack_b) > 1 &&
				(stack_b->first->nbr >
				get(stack_b, ft_lstlen(stack_b) - 1)->nbr))
			ft_printf("rb\n", rotate(stack_b));
	}
}
