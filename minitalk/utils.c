#include "./minitalk.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	while (*str == '\n' || *str == '\t' || *str == ' '
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '+')
	{
		sign = 1;
		str++;
	}
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str++;
	}
	return (sign * n);
}

long long		numdigit(long long n)
{
	long long	digit;

	digit = 1;
	n = n / 10;
	while (n > 0)
	{
		n = n / 10;
		digit = digit * 10;
	}
	return (digit);
}

void			putnum(long long num, int fd)
{
	long long	digit;
	long long	n;
	char		c;
	long long	i;

	digit = numdigit(num);
	i = num;
	while (i > 0)
	{
		n = num / digit;
		c = (char)n + '0';
		write(fd, &c, 1);
		num = num % digit;
		digit = digit / 10;
		i = i / 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = (long long)n;
	if (num < 0)
	{
		num = num * -1;
		write(fd, "-", 1);
	}
	else if (n == 0)
		write(fd, "0", 1);
	putnum(num, fd);
}

size_t	ft_strlen(const char *str)
{
	const char *temp;

	temp = str;
	while (*temp != '\0')
	{
		temp++;
	}
	return (temp - str);
}