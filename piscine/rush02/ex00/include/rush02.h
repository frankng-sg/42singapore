/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:13:42 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/09 20:03:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# define BUFFER_SIZE 4096 
# define INVALID_NUMBER "Error\n"
# define DICT_ERROR "Dict Error\n"

typedef struct s_record
{
	long long	key;
	char		*val;
}	t_record;
/* parse_dict.c */
int			ft_valid_dict_format(char *str);
t_record	*ft_parse_dict(char *filepath);
/* strio.c */
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putstrs(char **strs);
void		ft_putnbr(int nbr);
/* strutil.c */
int			ft_printable(char c);
int			ft_strlen(char *str);
int			ft_strslen(char **strs);
void		ft_strcpylr(char *dest, char *src, int l, int r);
void		ft_strcpy(char *dest, char *src);
/* strconv.c */
int			ft_valid_number(char *str);
long long	ft_atoi(char *str);
/* strsplit.c */
int			issep(char c, char *sep);
int			ft_count_words(char *str, char *sep);
char		**ft_split(char *str, char *sep);
/* stralloc.c */
void		ft_free_strs(char **strs);
/* sortdict.c */
int			ft_dictlen(t_record *dict);
int			ft_dictkeycmp(t_record k1, t_record k2);
void		ft_sortdict(t_record *dict);
/* dict.c */
void		ft_eval_key(t_record *dict, long long key);
/* dictalloc.c */
void		ft_free_dict(t_record *dict);
/* dictutil.c */
int			ft_count_valid_dict_records(char **strs);
char		*ft_get_val(t_record *dict, long long key);
#endif
