/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 13:38:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 15:10:22 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	free_str(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_strclr(tab[i++]);
	free(tab);
	tab = NULL;
}

int				check_duplicates(t_queue *queue)
{
	t_elem	*head;
	t_elem	*tmp;
	
	tmp = queue->first;
	while (tmp)
	{
		head = queue->first;
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

int				check_size(char *str)
{
	if ((str[0] != '-' && ft_strcmp(str, "2147483647") > 0 ) ||
			(str[0] == '-' && ft_strcmp(str, "-2147483648") > 0))
		return (0);
	return (1);
}

int				check_error(char *str, t_queue **queue)
{
	int i;

	i = 0;
	if (!ft_strlen(str))
		return (1);
	if (ft_strlen(str) >= 10)
	{
		if (!check_size(str))
			return (0);
	}
	if (str[i] == '-')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	thread(*queue, ft_atoi(str));
	if (!check_duplicates(*queue))
		return (0);
	return (1);
}

int				multi_nbr(const char *argv, t_queue **queue)
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
		{
			free_str(tab);
			return (0);
		}
		i++;
	}
	free_str(tab);
	return (ret);
}

int				parse_param(const char *argv[], t_queue **queue)
{
	int		i;

	i = 0;
	*queue = init();
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!multi_nbr(argv[i], queue))
				return (0);
		}
		else if (!check_error((char *)argv[i], queue))
			return (0);
		i++;
	}
	return (1);
}
