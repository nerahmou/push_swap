/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:20:20 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 11:37:12 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr(const wchar_t *str)
{
	int ret;

	ret = 0;
	if (str)
		while (*str)
			ret += ft_putwchar(*str++);
	return (ret);
}
