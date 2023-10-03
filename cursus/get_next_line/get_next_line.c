/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:23:24 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/03 13:54:01 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *s, int n)
{
	while (--n >= 0)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

void	*do_readbuf(int fd, char *data, char *buf)
{
	int		loc;
	int		len;
	char	*tmp;

	loc = 0;
	len = ft_strlen(data);
	while (!has_newline(&data[loc], len))
	{
		loc += len;
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = 0;
		tmp = ft_strjoin(data, buf);
		free(data);
		data = tmp;
	}
	free(buf);
	if (len < 0)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

static char	*readbuf(int fd, char *data)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(data);
		return (NULL);
	}
	buf[0] = '\0';
	return (do_readbuf(fd, data, buf));
}

static char	*nextline(char *data)
{
	char	*ptr;

	ptr = ft_strchr(data, '\n');
	if (ptr == NULL)
		return (ft_strdup(data));
	return (ft_substr(data, 0, ptr - data + 1));
}

char	*get_next_line(int fd)
{
	static char	*data = {0};
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data = readbuf(fd, data);
	if (data != NULL && *data == 0)
	{
		free(data);
		data = NULL;
	}
	if (data == NULL)
		return (NULL);
	line = nextline(data);
	tmp = ft_strdup(&data[ft_strlen(line)]);
	free(data);
	data = tmp;
	return (line);
}
//
//int	main(void)
//{
//	int	fd;
//	int	i;
//	char	*line;
//
//	fd = open("buflen.inp", O_RDONLY);
//	i = 0;
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (line == NULL)
//			return (0);
//		printf("LINE %d: %s", ++i, line);
//		free(line);
//	}
//}
