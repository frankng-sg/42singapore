/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:54:20 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/09 19:00:08 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

char	*ft_parse_val(char *val)
{
	int		l;
	int		r;
	int		i;
	char	*str;

	l = 0;
	while (val[l] == ' ')
		l++;
	r = ft_strlen(val) - 1;
	while (val[r] == ' ')
		r--;
	str = (char *)malloc((r - l + 2) * sizeof(char));
	i = 0;
	while (l <= r)
	{
		str[i] = val[l];
		i++;
		l++;
	}
	str[i] = 0;
	return (str);
}

int	ft_initial_entries(long long key)
{
	if (0 <= key && key <= 20)
		return (1);
	if (key == 30 || key == 40 || key == 50 || key == 60)
		return (1);
	if (key == 70 || key == 80 || key == 90 || key == 100)
		return (1);
	if (key == 1000 || key == 1000000 || key == 1000000000)
		return (1);
	return (0);
}

int	ft_valid_dict_format(char *str)
{
	int	valid;

	valid = 0;
	while (*str >= '0' && *str <= '9')
	{
		valid = 1;
		str++;
	}
	if (!valid)
		return (0);
	while (*str != 0 && *str != ':')
		str++;
	if (*str != ':')
		return (0);
	str++;
	while (*str != 0 && *str == ' ')
		str++;
	return (ft_printable(*str));
}

t_record	*ft_dict_from_strs(char **strs)
{
	t_record	*dict;
	int			len;
	int			i;
	int			j;
	char		**kv;

	len = ft_count_valid_dict_records(strs);
	if (len < 0)
		return (NULL);
	dict = (t_record *)malloc((len + 1) * sizeof(t_record));
	i = 0;
	j = 0;
	while (strs[j] != 0)
	{
		kv = ft_split(strs[j], ":");
		dict[i].key = ft_atoi(kv[0]);
		if (!ft_initial_entries(dict[i].key))
			dict[i].key = -1;
		dict[i].val = ft_parse_val(kv[1]);
		ft_free_strs(kv);
		i++;
		j++;
	}
	dict[len].val = 0;
	return (dict);
}

t_record	*ft_parse_dict(char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	size_t		bytes;
	char		buf[BUFFER_SIZE];
	char		**lines;
	t_record	*dict;

	if (fd < 0)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buf[bytes] = 0;
	lines = ft_split(buf, "\n");
	dict = ft_dict_from_strs(lines);
	ft_free_strs(lines);
	if (dict == NULL)
		return (NULL);
	ft_sortdict(dict);
	if (close(fd) < 0)
	{
		ft_free_dict(dict);
		return (NULL);
	}
	return (dict);
}
