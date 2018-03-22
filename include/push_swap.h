/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 14:15:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:13:43 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NEXT 1
# define LAST 2
# define NEXT_LAST 3
# include "../libft/libft.h"

/*
** function to store :	first, next and last number of the list
**						and if we are int the list a
*/
typedef struct		s_fnlp
{
	int				first;
	int				next;
	int				last;
}					t_fnlp;

t_queue				*init();
void				thread(t_queue *queue, int nbr);
void				process(t_queue *queue);
void				display_queue(t_queue *queue);
void				display_queue_rev(t_queue *queue);
void				queue_clr(t_queue **queue);

int					parse_param(const char *argv[], t_queue **queue);
int					operations(t_queues s_c);
int					check_sort(t_queue *queue, int rev);
int					check_pos(t_queue *queue);
int					check_pos_rev(t_queue *queue);
t_elem				*get(t_queue *queue, char c);

int					swap(t_queue *queue);
int					push(t_queue *dest, t_queue *src);
int					rotate(t_queue *queue);
int					reverse(t_queue *queue);

int					easy_sort(t_queue *queue_a, t_queue *queue_b);

#endif
