/*
* functions related to parsing the arguments
*/
#include "push_swap.h"

//check if c is a white space
static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

//convert a string to an int (handle overflow if > MAX_LONG)
int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	a;
	long	past_a;

	sign = 1;
	past_a = 0;
	i = 0;
	a = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + (str[i++] - '0');
		if (((a - str[i - 1] + '0') / 10) != past_a)
			return ((-sign - 1) / 2);
		past_a = a;
	}
	return (sign * a);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
* check if str is a valid argument;
* allowed syntax: A, +A, -A (with A in [0, 9])
*/
int	valid_arg(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_digit(str[i]) && str[i])
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}