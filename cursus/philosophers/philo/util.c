#include "philo.h"

// ft_isnumeric returns 1 if the string is numeric, 0 otherwise
int	ft_isnumeric(const char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

// ft_atoi converts a string to an integer
int	ft_atoi(const char *s)
{
	int	n;

	if (s == NULL)
		return (0);
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

// ft_memset fills the first n bytes of the memory area pointed to by s with the
// constant byte c
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*v;

	v = (unsigned char *)s;
	while (n-- > 0)
		*v++ = (unsigned char)c;
	return (s);
}

// ft_malloc allocates memory and initializes it to 0
void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	(void)ft_memset(ptr, '\0', size);
	return (ptr);
}

int	ft_putstr(char *str)
{
	int	nchars;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	nchars = 0;
	while (*str)
	{
		write(1, str++, 1);
		nchars++;
	}
	return (nchars);
}
