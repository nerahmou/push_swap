/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 11:27:04 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:13:42 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_queue	*init()
{
	t_queue	*pile;
	//t_elem *elem;

	pile = malloc(sizeof(*pile));
	//elem = malloc(sizeof(*elem));
	if (pile == NULL)
		return (NULL);
	//elem->nbr = 0;
	//elem->next = NULL;
	//pile->first = elem;
	return (pile);
}

//-----------------------------------------------

void	enfiler(t_queue *pile, int nbr)
{
	t_elem *new;
	t_elem *tmp;

	new = malloc(sizeof(*new));
	tmp = NULL;
	if (pile == NULL || new == NULL)
		return ;
	new->nbr = nbr;
	new->next = NULL;
	if (pile->first != NULL)
	{
		tmp = pile->first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		pile->first = new;

}

void	defiler(t_queue *pile)
{
	t_elem *tmp;

	tmp = NULL;
	if (pile == NULL)
		return ;
	if (pile->first != NULL)
	{
		tmp = pile->first;
		pile->first = tmp->next;
		free(tmp);
	}
}

void	display_file(t_queue *pile)
{
	t_elem *tmp;

	tmp = pile->first;
	while (tmp != NULL)
	{
		ft_printf("[%d]-->",tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("[NULL]\n");
}
