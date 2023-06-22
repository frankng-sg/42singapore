/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:54:08 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 14:58:17 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#define BUFF1 8000000

void	ft_concat(char *dest, char *src, int *size, int buff_size)
{
	int		i;
	int		c;

	i = 0;
	if ((*size) > buff_size && (*size) % buff_size == 0)
	{
		if (dest[*size - buff_size])
			i = *size - buff_size;
	}
	c = 0;
	while (dest[i])
		i++;
	while (src[c] && c < buff_size)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	while (c >= 0)
	{
		src[c] = '\0';
		c--;
	}
	dest[i] = '\0';
}

void	ft_read2(char **str, char *buff, int *size, int buff_size)
{
	char	*prevstr;

	prevstr = *str;
	*str = (char *)malloc(sizeof(*str) * (*size + 1));
	ft_strcpy(*str, prevstr);
	ft_concat(*str, buff, size, buff_size);
	str[0][*size] = '\0';
	free(prevstr);
}

char	*ft_read(int fd, int buff_size, int size)
{
	char	buff[BUFF1];
	char	*str;
	int		bytes;
	int		nrows;
	int		i;

	nrows = 0;
	i = 0;
	str = (char *)malloc(sizeof(char));
	str[0] = 0;
	while (i <= nrows)
	{
		bytes = read(fd, buff, BUFF1);
		if (bytes <= 0)
			break ;
		if (nrows == 0)
			nrows = ft_atoi(buff);
		size += bytes;
		ft_read2(&str, buff, &size, buff_size);
		i++;
	}
	return (str);
}

void	temp_read(int fd)
{
	char	*str;

	str = ft_read(fd, BUFF1, 0);
	ft_start(str);
	free(str);
	close(fd);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		fd;

	str = NULL;
	i = 0;
	if (argc <= 1)
	{
		str = ft_read(0, BUFF1, 0);
		ft_start(str);
		free(str);
		return (0);
	}
	while (argc > ++i)
	{
		if (i > 1)
			ft_putchar('\n');
		fd = open(argv[i], O_RDONLY);
		if (fd > 0)
			temp_read(fd);
		else
			ft_putstr("map error\n");
	}
	return (0);
}
