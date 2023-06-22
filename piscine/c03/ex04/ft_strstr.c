/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:37:55 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/28 11:22:05 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	register char	*a;
	register char	*b;

	if (*to_find == 0)
		return (str);
	b = to_find;
	while (*str != 0)
	{
		if (*str != *b)
		{
			str++;
			continue ;
		}
		a = str;
		while (1)
		{
			if (*b == 0)
				return (str);
			if (*a++ != *b++)
				break ;
		}
		b = to_find;
		str++;
	}
	return ((void *)0);
}
