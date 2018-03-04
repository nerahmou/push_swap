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

t_queue	*init(void)
{
	t_queue	*queue;

	if (!(queue = malloc(sizeof(*queue))))
		return (NULL);
	queue->first = NULL;
	return (queue);
}

void	thread(t_queue *queue, int nbr)
{
	t_elem *new;
	t_elem *tmp;

	new = malloc(sizeof(*new));
	tmp = NULL;
	if (queue == NULL || new == NULL)
		return ;
	new->nbr = nbr;
	new->next = NULL;
	if (queue->first != NULL)
	{
		tmp = queue->first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		queue->first = new;
}

void	process(t_queue *queue)
{
	t_elem *tmp;

	tmp = NULL;
	if (queue == NULL)
		return ;
	if (queue->first != NULL)
	{
		tmp = queue->first;
		queue->first = tmp->next;
		free(tmp);
	}
}

void	display_queue(t_queue *queue)
{
	t_elem *tmp;

	tmp = NULL;
	if (queue->first == NULL)
	{
		ft_printf("Liste vide\n");
		return ;
	}
	tmp = queue->first;
	while (tmp != NULL)
	{
		ft_printf("[%d]-->",tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("[NULL]\n");
}
