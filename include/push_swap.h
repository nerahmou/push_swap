/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 14:15:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 10:06:23 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

t_queue				*init();
void				thread(t_queue *queue, int nbr);
void				process(t_queue *queue);
void				display_queue(t_queue *queue);
void				queue_clr(t_queue **queue);

int					parse_param(const char *argv[], t_queue **queue);
int					operations(t_queues s_c);

int					swap(t_queue *queue);
int					push(t_queue *dest, t_queue *src);
int					rotate(t_queue *queue);
int					reverse(t_queue *queue);
#endif
