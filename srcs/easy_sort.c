/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easy_sort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:02:31 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:28 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ultime_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_a;
	int	pos_b;

	if ((pos_a = check_pos(stack_a, 0)))
	{
		pos_b = check_pos_rev(stack_a, 0);
		if (pos_b + 1 < pos_a)
		{
			pos_b += 1;
			while (pos_b--)
				ft_printf("rra\n", reverse(stack_a));
		}
		else
			while (pos_a--)
				ft_printf("ra\n", rotate(stack_a));
	}
	if (!check_sort(stack_a))
		ft_printf("pb\n", push(stack_b, stack_a));
}

int			easy_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int	next;
	int	last;

	while (!check_sort(stack_a))
	{
		first = stack_a->first->nbr;
		next = get(stack_a, 1)->nbr;
		last = get(stack_a, ft_lstlen(stack_a) - 1)->nbr;
		if (first > last)
			ft_printf("ra\n", rotate(stack_a));
		else if (first > next)
			ft_printf("sa\n", swap(stack_a));
		else
			ultime_sort(stack_a, stack_b);
	}
	while (stack_b->first)
		ft_printf("pa\n", push(stack_a, stack_b));
	return (1);
}
