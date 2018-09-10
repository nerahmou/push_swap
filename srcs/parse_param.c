/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:35 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		check_duplicates(t_stack *stack)
{
	t_elem	*head;
	t_elem	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		head = stack->first;
		tmp = tmp->next;
		while (tmp && head)
		{
			if (tmp->nbr == head->nbr && tmp != head)
				return (0);
			head = head->next;
		}
	}
	return (1);
}

static int		check_error(char *str, t_stack **stack)
{
	int i;

	i = 0;
	if (!ft_strlen(str))
		return (0);
	if (ft_strlen(str) >= 10 &&
			((str[0] != '-' && ft_strcmp(str, "2147483647") > 0) ||
				(str[0] == '-' && ft_strcmp(str, "-2147483648") > 0)))
		return (0);
	if (str[i] == '-')
		if (str[++i] == '0')
			return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	thread(*stack, ft_atoi(str));
	if (!check_duplicates(*stack))
		return (0);
	return (1);
}

static int		multi_nbr(const char *argv, t_stack **stack)
{
	char	**tab;
	int		i;
	int		ret;

	tab = ft_strsplit(argv, ' ');
	i = -1;
	ret = 1;
	while (tab[++i])
	{
		if (!(ret = check_error(tab[i], stack)))
			break ;
	}
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
	return (ret);
}

int				parse_param(const char *argv[], t_stack **stack)
{
	int		i;

	i = -1;
	*stack = init();
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!multi_nbr(argv[i], stack))
				return (0);
		}
		else if (!check_error((char *)argv[i], stack))
			return (0);
	}
	if (((*stack)->len = ft_lstlen(*stack)) == 1)
	{
		stack_clr(stack);
		if (!ft_strcmp(argv[-1], "./checker"))
			ft_printf("{green}{bold}OK{eoc}\n");
		exit(EXIT_SUCCESS);
	}
	return (1);
}
