/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:45:28 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/01 20:27:00 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*readwbuff(int fd, char *line)
{
	char	*buff;
	ssize_t	nbytes;

	buff = (char *)malloc((BUFFER_SIZE + 1));
	if (buff == NULL)
		return (line);
	while (ft_strchr(line, '\n') == NULL)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes <= 0)
			break ;
		buff[nbytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

static char	*frontcut(char *data, size_t n)
{
	char	*out;

	out = ft_strdup(&data[n]);
	free(data);
	return (out);
}

char	*ft_getline(char *data)
{
	int		len;
	char	*line;

	len = 0;
	while (data[len] != '\n' && data[len])
		len++;
	if (data[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (line == NULL)
		return (NULL);
	line[len] = 0;
	line[--len] = '\n';
	while (--len >= 0)
		line[len] = data[len];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = readwbuff(fd, data);
	if (data == NULL || data[0] == 0)
	{
		free(data);
		return (NULL);
	}
	line = ft_getline(data);
	if (line == NULL)
		free(data);
	else
		data = frontcut(data, ft_strlen(line));
	return (line);
}

int	main(void)
{
	char	*s;
	int	i;
	int	fd;

	fd = open("testdata/onechar.inp", O_RDONLY);
	if (fd < 0)
	{
		printf("Error reading file\n");
		return (1);
	}
	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return (0);
		i++;
		printf("LINE %d: %s", i, s);
		free(s);
	}
}
