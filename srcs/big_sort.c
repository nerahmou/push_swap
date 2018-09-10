/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   medium_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 12:10:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:19 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ultime_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_a;
	int	pos_b;
	int swp;

	swp = 0;
	if ((pos_a = check_pos(stack_b, 1)))
	{
		pos_b = check_pos_rev(stack_b, 1);
		if (pos_b < pos_a)
		{
			pos_b += 1;
			while (pos_b--)
				ft_printf("rrb\n", reverse(stack_b));
		}
		else
		{
			while (pos_a-- > 0)
				ft_printf("rb\n", rotate(stack_b), swp = 1);
			if (swp)
				ft_printf("sb\n", swap(stack_b));
		}
	}
	ft_printf("pa\n", push(stack_a, stack_b));
}

int			big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstlen(stack_a) > 200)
		while (ft_lstlen(stack_a) > 2)
			partition_big(stack_a, stack_b);
	else
		while (ft_lstlen(stack_a) > 2)
			partition_med(stack_a, stack_b);
	if (!check_sort(stack_a))
		ft_printf("sa\n", swap(stack_a));
	while (ft_lstlen(stack_b))
		ultime_sort(stack_a, stack_b);
	return (1);
}
