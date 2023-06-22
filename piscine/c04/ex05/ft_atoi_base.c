/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:55:22 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/28 21:52:12 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_invalid_base(char c)
{
	if (c == '+' || c == '-' || ft_isspace(c))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

int	ft_strtoi_base(char *str, char *base, int lbase)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
			if (base[j++] == base[i])
				return (0);
		if (ft_invalid_base(base[i]))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	while (ft_isspace(*str))
		str++;
	j = 0;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			j++;
	j = 1 - (j % 2) * 2;
	return (j * ft_strtoi_base(str, base, i));
}
