/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 14:15:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/11 11:14:52 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

t_stack				*init();
void				thread(t_stack *stack, int nbr);
void				process(t_stack *stack);
void				display_stack(t_stack *stack_a, t_stack *stack_b);
void				display_stack_rev(t_stack *stack);
void				stack_clr(t_stack **stack);
t_elem				*get(t_stack *stack, int pos);

int					parse_param(const char *argv[], t_stack **stack);
int					operations(t_stacks s_c);
int					check_low(t_stack *stack, int pivot, int rev);
int					check_sort(t_stack *stack);
int					check_pos(t_stack *stack, int rev);
int					check_pos_rev(t_stack *stack, int rev);

int					swap(t_stack *stack);
int					push(t_stack *dest, t_stack *src);
int					rotate(t_stack *stack);
int					reverse(t_stack *stack);

int					easy_sort(t_stack *stack_a, t_stack *stack_b);
int					big_sort(t_stack *stack_a, t_stack *stack_b);

void				partition_med(t_stack *stack_a, t_stack *stack_b);
void				partition_big(t_stack *stack_a, t_stack *stack_b);
#endif
