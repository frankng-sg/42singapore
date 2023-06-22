/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:59:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/13 15:15:40 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

void	ft_convert(t_record *dict, char *str)
{
	long long	key;

	if (!ft_valid_number(str))
		return (ft_putstr(INVALID_NUMBER));
	key = ft_atoi(str);
	if (key < 0)
		return (ft_putstr(INVALID_NUMBER));
	ft_eval_key(dict, key);
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	t_record	*dict;
	char		*key;

	dict = NULL;
	if (argc == 2)
	{
		dict = ft_parse_dict("numbers.dict");
		key = argv[1];
	}
	else if (argc == 3)
	{
		dict = ft_parse_dict(argv[1]);
		key = argv[2];
	}
	if (dict == NULL)
	{
		ft_putstr(DICT_ERROR);
		return (1);
	}
	ft_convert(dict, key);
	ft_free_dict(dict);
	return (0);
}
