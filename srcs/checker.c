/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:25 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int argc, const char *argv[])
{
	t_stacks	s_c;

	if (argc > 1)
	{
		if (!parse_param(++argv, &(s_c.stack_a)))
			ft_printf("{bold}{red}Error\n{eoc}");
		else
		{
			s_c.stack_a->name = 'A';
			s_c.stack_b = init();
			s_c.stack_b->name = 'B';
			display_stack(s_c.stack_a, s_c.stack_b);
			while (get_next_line(0, &s_c.operation))
			{
				operations(s_c);
				ft_strdel(&s_c.operation);
				display_stack(s_c.stack_a, s_c.stack_b);
			}
			if (check_sort(s_c.stack_a) && !ft_lstlen(s_c.stack_b))
				ft_printf("{green}{bold}OK{eoc}\n");
			else
				ft_printf("{red}{bold}KO{eoc}\n");
			stack_clr(&s_c.stack_b);
		}
		stack_clr(&s_c.stack_a);
	}
	return (0);
}
