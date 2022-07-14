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
long	ft_atoi0(const char *str)
{
	int		sign;
	int		i;
	long	a;

	sign = 1;
	i = 0;
	a = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		a = (a * 10) + (str[i++] - '0');
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
/*
* check if number is an int or not
*/
int	is_int(long a)
{
	if (a > INT_MAX || a < INT_MIN)
		return (0);
	return (1);
}