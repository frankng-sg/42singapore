#include "rush02.h"
#include <stdlib.h>

void	ft_printkv(long long key, char *val)
{
	if (key < 100)
		ft_putstr(val);
	else
	{
		ft_putstr("one ");
		ft_putstr(val);
	}
}

int	ft_require_comma(long long key)
{
	return (key == 1000 || key == 1000000 || key == 1000000000);
}

void	ft_eval(t_record *dict, int i, long long key)
{
	long long	mod;
	long long	div;

	div = key / dict[i].key;
	mod = key % dict[i].key;
	if (div == 1 && dict[i].key < 100)
	{
		ft_putstr(dict[i].val);
		if (mod > 0 && mod < 10)
			ft_putstr("-");
	}
	else
	{
		ft_eval_key(dict, div);
		ft_putstr(" ");
		ft_putstr(dict[i].val);
		if (mod > 0)
		{
			if (ft_require_comma(dict[i].key))
				ft_putstr(",");
			ft_putstr(" ");
		}
	}
	if (mod > 0)
		ft_eval_key(dict, mod);
}

void	ft_eval_key(t_record *dict, long long key)
{
	int		i;
	char	*val;

	val = ft_get_val(dict, key);
	if (val != NULL)
		return (ft_printkv(key, val));
	i = 0;
	while (dict[i].key > key && dict[i].val != 0)
		i++;
	ft_eval(dict, i, key);
}
