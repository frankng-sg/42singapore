/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:58:11 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 10:52:01 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_isspace(char c);
int		ft_invalid_base(char *base);
void	ft_swap(char *a, char *b);

int	ft_do_atoi(char *str, char *base, int lbase)
{
	char	map[256];
	int		i;
	int		num;

	i = 0;
	while (i < 256)
		map[i++] = -1;
	i = 0;
	while (i < lbase)
	{
		map[(int)base[i]] = i;
		i++;
	}
	num = 0;
	i = 0;
	while (map[(int)str[i]] != -1)
	{
		num = num * lbase + map[(int)str[i]];
		i++;
	}
	return (num);
}

int	ft_atoi(char *str, char *base, int lbase)
{
	int	sign;

	while (ft_isspace(*str))
		str++;
	sign = 0;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign++;
	sign = 1 - ((sign % 2) << 1);
	return (sign * ft_do_atoi(str, base, lbase));
}	

char	*ft_do_itoa(char *ch, long n, char *base, int lbase)
{
	int	i;
	int	j;

	i = 0;
	while (n != 0)
	{
		ch[i] = base[n % lbase];
		n /= lbase;
		i++;
	}
	ch[i--] = 0;
	j = 0;
	while (j < i)
		ft_swap(&ch[i--], &ch[j++]);
	return ((char *)ch);
}

char	*ft_itoa(int num, char *base, int lbase)
{
	char	*ch;
	char	*chaddr;
	long	n;

	ch = (char *)malloc(128 * sizeof(char));
	chaddr = ch;
	if (num == 0)
	{
		ch[0] = base[0];
		ch[1] = 0;
		return ((char *)ch);
	}
	n = (long)num;
	if (n < 0)
	{
		*ch++ = '-';
		n = -n;
	}
	ft_do_itoa(ch, n, base, lbase);
	return (chaddr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;
	int	lbasefrom;
	int	lbaseto;

	if (ft_invalid_base(base_from) || ft_invalid_base(base_to))
		return ((void *)0);
	lbasefrom = ft_strlen(base_from);
	lbaseto = ft_strlen(base_to);
	num = ft_atoi(nbr, base_from, lbasefrom);
	return (ft_itoa(num, base_to, lbaseto));
}
