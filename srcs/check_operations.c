/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_operations.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 21:42:22 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 13:44:05 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	push_queue(t_queues s_c)
{
	if (s_c.operation[1] == 'a')
		push(s_c.queue_a, s_c.queue_b);
	else
		push(s_c.queue_b, s_c.queue_a);
	return (1);
}

static int	swap_queue(t_queues s_c)
{
	if (s_c.operation[1] == 'a')
		swap(s_c.queue_a);
	else if (s_c.operation[1] == 'b')
		swap(s_c.queue_b);
	else
	{
		swap(s_c.queue_a);
		swap(s_c.queue_b);
	}
	return (1);
}

static int	reverse_queue(t_queues s_c)
{
	if (s_c.operation[2] == 'a')
		reverse(s_c.queue_a);
	else if (s_c.operation[2] == 'b')
		reverse(s_c.queue_b);
	else
	{
		reverse(s_c.queue_a);
		reverse(s_c.queue_b);
	}
	return (1);
}

static int	rotate_queue(t_queues s_c)
{
	if (s_c.operation[1] == 'a')
		rotate(s_c.queue_a);
	else if (s_c.operation[1] == 'b')
		rotate(s_c.queue_b);
	else
	{
		rotate(s_c.queue_a);
		rotate(s_c.queue_b);
	}
	return (1);
}

int			operations(t_queues s_c)
{
	if (!ft_strcmp(s_c.operation, "pa") || !ft_strcmp(s_c.operation, "pb"))
		return (push_queue(s_c));
	if (!ft_strcmp(s_c.operation, "sa") || !ft_strcmp(s_c.operation, "sb")
			|| !ft_strcmp(s_c.operation, "ss"))
		return (swap_queue(s_c));
	if (!ft_strcmp(s_c.operation, "ra") || !ft_strcmp(s_c.operation, "rb")
			|| !ft_strcmp(s_c.operation, "rr"))
		return (rotate_queue(s_c));
	if (!ft_strcmp(s_c.operation, "rra") || !ft_strcmp(s_c.operation, "rrb")
			|| !ft_strcmp(s_c.operation, "rrr"))
		return (reverse_queue(s_c));
	queue_clr(&s_c.queue_a);
	queue_clr(&s_c.queue_b);
	ft_strdel(&s_c.operation);
	ft_printf("{bold}{red}Error\n{eoc}");
	exit(EXIT_FAILURE);
}
