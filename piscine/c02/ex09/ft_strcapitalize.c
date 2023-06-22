/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:57:28 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 21:06:22 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	char	is_first_letter;
	int		i;

	i = 0;
	is_first_letter = 1;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			str[i] = to_lower(str[i]);
			if (is_first_letter)
			{
				str[i] = to_upper(str[i]);
				is_first_letter = 0;
			}
		}
		else
			is_first_letter = 1;
		i++;
	}
	return (str);
}
