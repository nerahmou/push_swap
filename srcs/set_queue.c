/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 11:27:04 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 19:19:33 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_queue		*init(void)
{
	t_queue	*queue;

	if (!(queue = malloc(sizeof(*queue))))
		return (NULL);
	queue->first = NULL;
	return (queue);
}

void		thread(t_queue *queue, int nbr)
{
	t_elem *new;
	t_elem *tmp;

	new = malloc(sizeof(*new));
	if (queue == NULL || new == NULL)
		return ;
	new->nbr = nbr;
	new->prev = NULL;
	new->next = NULL;
	if (queue->first != NULL)
	{
		tmp = queue->first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		queue->first = new;
}

void		process(t_queue *queue)
{
	t_elem *tmp;

	if (queue == NULL)
		return ;
	if (queue->first != NULL)
	{
		tmp = queue->first;
		queue->first = tmp->next;
		if (queue->first)
			queue->first->prev = NULL;
		free(tmp);
	}
}

void		display_queue(t_queue *queue_a, t_queue *queue_b)
{
	t_queue	*tmp;
	t_queue	*tmp2;
	t_elem	*head;
	t_elem	*head2;

	head = queue_a->first;
	head2 = queue_b->first;
	tmp = queue_a;
	tmp2 = queue_b;
	ft_printf("       {red}-----------------{eoc}\n");
	while (ft_lstlen(tmp) > ft_lstlen(tmp2))
		ft_printf("      |{bold}{Bblue}%5d   {eoc}|        |\n",
				tmp->first->nbr, tmp->first = tmp->first->next);
	while (ft_lstlen(tmp2) > ft_lstlen(tmp))
		ft_printf("      |        |{bold}{Bred}%5d   {eoc}|\n",
				tmp2->first->nbr, tmp2->first = tmp2->first->next);
	while (tmp->first)
		ft_printf("      |{bold}{Bblue}%5d   {eoc}|{bold}{Bred}%5d   {eoc}|\n",
				tmp->first->nbr, tmp2->first->nbr,
				tmp->first = tmp->first->next,
				tmp2->first = tmp2->first->next);
	ft_printf("       {red}-----------------{eoc}\n");
	queue_a->first = head;
	queue_b->first = head2;
}

void		queue_clr(t_queue **queue)
{
	t_queue	*head;
	t_elem	*tmp;

	head = *queue;
	tmp = (*queue)->first;
	if (queue != NULL)
	{
		while (tmp != NULL)
		{
			(*queue)->first = tmp->next;
			free(tmp);
			tmp = (*queue)->first;
		}
		free(*queue);
		queue = NULL;
	}
}
