/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:04:58 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:41 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int argc, const char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc > 1)
	{
		if (!parse_param(++argv, &(stack_a)))
			ft_printf("{bold}{red}Error\n{eoc}");
		else
		{
			stack_a->name = 'A';
			stack_b = init();
			stack_b->name = 'B';
			if (check_sort(stack_a))
				;
			else if (stack_a->len <= 50)
				easy_sort(stack_a, stack_b);
			else
				big_sort(stack_a, stack_b);
			stack_clr(&stack_b);
		}
		stack_clr(&stack_a);
	}
	return (0);
}
