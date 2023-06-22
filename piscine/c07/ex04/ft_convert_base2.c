/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:34:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/05 20:14:27 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_invalid_base(char *base)
{
	int	map[256];
	int	i;

	if (base == 0 || ft_strlen(base) <= 1)
		return (1);
	i = 0;
	while (i < 256)
	{
		map[i] = 0;
		i++;
	}
	while (*base != 0)
	{
		if (*base == '+' || *base == '-' || ft_isspace(*base))
			return (1);
		if (map[(int)*base] == 1)
			return (1);
		map[(int)*base] = 1;
		base++;
	}
	return (0);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
