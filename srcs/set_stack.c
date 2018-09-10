/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 11:27:04 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 15:56:45 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack		*init(void)
{
	t_stack	*stack;

	if (!(stack = malloc(sizeof(*stack))))
		return (NULL);
	stack->first = NULL;
	return (stack);
}

void		thread(t_stack *stack, int nbr)
{
	t_elem *new;
	t_elem *tmp;

	new = malloc(sizeof(*new));
	if (stack == NULL || new == NULL)
		return ;
	new->nbr = nbr;
	new->prev = NULL;
	new->next = NULL;
	if (stack->first != NULL)
	{
		tmp = stack->first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		stack->first = new;
}

void		process(t_stack *stack)
{
	t_elem *tmp;

	if (stack == NULL)
		return ;
	if (stack->first != NULL)
	{
		tmp = stack->first;
		stack->first = tmp->next;
		if (stack->first)
			stack->first->prev = NULL;
		free(tmp);
	}
}

void		display_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_elem	*head;
	t_elem	*head2;

	head = stack_a->first;
	head2 = stack_b->first;
	tmp = stack_a;
	tmp2 = stack_b;
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
	stack_a->first = head;
	stack_b->first = head2;
}

void		stack_clr(t_stack **stack)
{
	t_stack	*head;
	t_elem	*tmp;

	head = *stack;
	tmp = (*stack)->first;
	if (stack != NULL)
	{
		while (tmp != NULL)
		{
			(*stack)->first = tmp->next;
			free(tmp);
			tmp = (*stack)->first;
		}
		free(*stack);
		stack = NULL;
	}
}
