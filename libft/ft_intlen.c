/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/29 19:58:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/29 20:37:43 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(long n, int base)
{
	int length;

	length = 0;
	if (n <= 0)
		length++;
	n = ft_abs(n);
	while (n != 0)
	{
		length++;
		n = n / base;
	}
	return (length);
}
