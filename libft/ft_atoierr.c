
#include "libft.h"

int		ft_atoierr(const char *str)
{
	int sign;
	int output;

	output = -1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str >= '0' && *str <= '9')
		output = 0;
	else
		return (-1);
	while (*str >= '0' && *str <= '9')
		output = (output * 10) + *str++ - '0';
	return (sign * output);
}
