#include "../includes/philo_three.h"

void	ft_convert(int n, char *s, int *i)
{
	if (n > 9)
		ft_convert(n / 10, s, i);
	s[*i] = n % 10 + 48;
	*i = *i + 1;
	s[*i] = 0;
}

void		ft_itoa(char *s, int n)
{
	int		i;

	if (n == -2147483648)
	{
		s[0] = '-';
		s[1] = '2';
		n = 147483648;
		i = 2;
	}
	else if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		i = 1;
	}
	else
		i = 0;
	ft_convert(n, s, &i);
}