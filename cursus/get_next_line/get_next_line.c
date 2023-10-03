/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartin <gemartin@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:41:32 by gemartin          #+#    #+#             */
/*   Updated: 2023/10/01 16:27:20 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*prunestr(char *data, size_t n)
{
	char	*out;

	out = ft_substr(data, 0, n);
	ft_cleanstr(data);
	return (out);
}

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

static char	*readbuf(int fd, char *data)
{
	char	*buf;
	int		loc;
	int		len;	

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (ft_cleanstr(data));
	buf[0] = '\0';
	loc = 0;
	len = ft_strlen(data);
	while (has_newline(&data[loc], len))
	{
		loc += len;
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[loc] = 0;
		data = ft_strjoin(data, buf);
	}
	free(buf);
	if (len == -1)
		return (ft_cleanstr(data));
	return (data);
}

static char	*nextline(char *data)
{
	char	*ptr;

	ptr = ft_strchr(data, '\n');
	return (ft_substr(data, 0, ptr - data + 1));
}

char	*get_next_line(int fd)
{
	static char	*data = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	data = readbuf (fd, data);
	if (data == NULL)
		return (NULL);
	line = nextline(data);
	if (line == NULL)
		return (ft_cleanstr(data));
	data = prunestr(data, ft_strlen(line));
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;
	char	*line;

	fd = open("testdata/1char.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		printf("LINE %d: %s", ++i, line);
	}
}
