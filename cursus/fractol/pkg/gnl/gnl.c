/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:23:24 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/28 13:02:10 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "../libft/libft.h"

static char	*ft_free(char *s)
{
	if (s != NULL)
		free(s);
	return (NULL);
}

static char	*read_file(int fd, char *text, size_t buf_size)
{
	char	*buf;
	char	*tmp;
	ssize_t	nbytes;

	buf = (char *)malloc(buf_size + 1);
	if (buf == NULL)
		return (ft_free(text));
	nbytes = 0;
	while (ft_strchr(text, '\n') == NULL)
	{
		nbytes = read(fd, buf, buf_size);
		if (nbytes <= 0)
			break ;
		buf[nbytes] = 0;
		tmp = ft_strjoin(text, buf);
		free(text);
		text = tmp;
	}
	free(buf);
	if (nbytes < 0)
		return (ft_free(text));
	return (text);
}

static char	*get_line(char *text)
{
	char	*loc;

	loc = ft_strchr(text, '\n');
	if (loc == NULL)
		return (ft_strdup(text));
	return (ft_substr(text, 0, loc - text + 1));
}

static char	*front_trunc(char *text, size_t n)
{
	char	*out;

	if (text == NULL)
		return (NULL);
	if (n <= 0)
		return (text);
	if (n >= ft_strlen(text))
		return (ft_free(text));
	out = ft_strdup(&text[n]);
	free(text);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX] = {0};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	text[fd] = read_file(fd, text[fd], BUFFER_SIZE);
	line = get_line(text[fd]);
	text[fd] = front_trunc(text[fd], ft_strlen(line));
	return (line);
}
//
//int	main(void)
//{
//	char	*line;
//	int	fd;
//	int	i;
//
//	fd = open("one_char.inp", O_RDONLY);
//	i = 0;
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (line == NULL)
//			return (0);
//		printf("LINE %d: %s", i++, line);
//	}
//}
