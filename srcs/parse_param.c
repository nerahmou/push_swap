/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:42:34 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_error(char *str, t_queue *queue)
{
	queue = NULL;
	if (ft_strcmp(str, "2147483647") > 0 || ft_strcmp(str, "-2147483648") > 0)
		return (0);
	if (str[0] == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	multi_nbr(const char *argv, t_queue *queue)
{
	char	**tab;
	int		i;
	int		ret;

	tab = ft_strsplit(argv, ' ');
	i = 0;
	ret = 1;
	while (tab[i])
	{
		if (!(ret = check_error(tab[i], queue)))
			break ;
	}

	return (ret);
}

int	parse_param(const char *argv[])
{
	int i;
	t_queue *queue;

	i = 0;
	queue = init();
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			multi_nbr(argv[i], queue);
		else
		{
			check_error((char *)argv[i], queue);
			thread(queue, ft_atoi(argv[i]));
		}
		i++;
	}
	return (0);
}
