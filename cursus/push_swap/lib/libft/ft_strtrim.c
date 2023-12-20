/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:28:40 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 16:09:00 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	front;
	size_t	back;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = 0;
	back = ft_strlen(s1);
	if (back == 0)
		return (ft_strdup(""));
	back--;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (back >= front && ft_strchr(set, s1[back]))
		back--;
	return (ft_substr(s1, front, back - front + 1));
}
