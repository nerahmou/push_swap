/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 14:15:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 15:51:36 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct		s_queue
{
	struct	s_elem	*first;
}					t_queue;

typedef struct		s_elem
{
	int				nbr;
	struct	s_elem	*next;
}					t_elem;

typedef struct		s_queues
{
	t_queue	*queue_a;
	t_queue	*queue_b;
	char	*operation;
	int		rev;
}					t_queues;

t_queue				*init();
void				thread(t_queue *queue, int nbr);
void				process(t_queue *queue);
void				display_queue(t_queue *queue);
void				queue_clr(t_queue **queue);

int					parse_param(const char *argv[], t_queue **queue);
int					multi_nbr(const char *argv, t_queue **queue);
int					check_error(char *str, t_queue **queue);
int					push_swap(t_queues s_c);
#endif
