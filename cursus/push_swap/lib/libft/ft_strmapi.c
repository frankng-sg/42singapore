/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:26:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/28 10:30:10 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	slen;
	char	*out;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	out = (char *)malloc((slen + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	out[slen] = 0;
	i = 0;
	while (i < slen)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}
