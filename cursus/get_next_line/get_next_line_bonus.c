/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:23:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/03 13:34:59 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*data[OPEN_MAX + 1] = {0};
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	data[fd] = readbuf(fd, data[fd]);
	if (data[fd] != NULL && *(data[fd]) == 0)
	{
		free(data[fd]);
		data[fd] = NULL;
	}
	if (data[fd] == NULL)
		return (NULL);
	line = nextline(data[fd]);
	tmp = ft_strdup(&data[fd][ft_strlen(line)]);
	free(data[fd]);
	data[fd] = tmp;
	return (line);
}
//
//int	main(void)
//{
//	int	fd;
//	int	i;
//	char	*line;
//
//	fd = open("testdata/1char.txt", O_RDONLY);
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
