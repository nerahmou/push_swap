/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_operations.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:42:22 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:22 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	push_stack(t_stacks s_c)
{
	if (s_c.operation[1] == 'a')
		push(s_c.stack_a, s_c.stack_b);
	else
		push(s_c.stack_b, s_c.stack_a);
	return (1);
}

static int	swap_stack(t_stacks s_c)
{
	if (s_c.operation[1] == 'a')
		swap(s_c.stack_a);
	else if (s_c.operation[1] == 'b')
		swap(s_c.stack_b);
	else
	{
		swap(s_c.stack_a);
		swap(s_c.stack_b);
	}
	return (1);
}

static int	reverse_stack(t_stacks s_c)
{
	if (s_c.operation[2] == 'a')
		reverse(s_c.stack_a);
	else if (s_c.operation[2] == 'b')
		reverse(s_c.stack_b);
	else
	{
		reverse(s_c.stack_a);
		reverse(s_c.stack_b);
	}
	return (1);
}

static int	rotate_stack(t_stacks s_c)
{
	if (s_c.operation[1] == 'a')
		rotate(s_c.stack_a);
	else if (s_c.operation[1] == 'b')
		rotate(s_c.stack_b);
	else
	{
		rotate(s_c.stack_a);
		rotate(s_c.stack_b);
	}
	return (1);
}

int			operations(t_stacks s_c)
{
	if (!ft_strcmp(s_c.operation, "pa") || !ft_strcmp(s_c.operation, "pb"))
		return (push_stack(s_c));
	if (!ft_strcmp(s_c.operation, "sa") || !ft_strcmp(s_c.operation, "sb")
			|| !ft_strcmp(s_c.operation, "ss"))
		return (swap_stack(s_c));
	if (!ft_strcmp(s_c.operation, "ra") || !ft_strcmp(s_c.operation, "rb")
			|| !ft_strcmp(s_c.operation, "rr"))
		return (rotate_stack(s_c));
	if (!ft_strcmp(s_c.operation, "rra") || !ft_strcmp(s_c.operation, "rrb")
			|| !ft_strcmp(s_c.operation, "rrr"))
		return (reverse_stack(s_c));
	stack_clr(&s_c.stack_a);
	stack_clr(&s_c.stack_b);
	ft_strdel(&s_c.operation);
	ft_printf("{bold}{red}Error\n{eoc}");
	exit(EXIT_FAILURE);
}
