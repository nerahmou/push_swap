/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 14:30:20 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:22:21 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static int	push_queue(t_queues s_c)
{
	if (s_c.operation[1] == 'a')
		push(s_c.queue_a, s_c.queue_b);
	else
		push(s_c.queue_b, s_c.queue_a);
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
	if (ft_strlen(s_c.operation) == 3)
		return (reverse_queue(s_c));
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

int			push_swap(t_queues s_c)
{
	if (s_c.operation[0] == 's')
		swap_queue(s_c);
	else if (s_c.operation[0] == 'p')
		push_queue(s_c);
	else
		rotate_queue(s_c);
	return (1);
}
