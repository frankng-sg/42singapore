/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 21:02:25 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_MSG "Error\n"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_new(int val);
t_stack	*ft_pop(t_stack *head);
t_stack	*ft_pop_last(t_stack *head);
t_stack	*ft_push(t_stack *head, int val);
t_stack *ft_push_last(t_stack *head, int val);
t_stack	*ft_rotate(t_stack *head);
t_stack	*ft_rrotate(t_stack *head);
t_stack	*ft_sort(t_stack *a);
t_stack *search(t_stack *head, int key);
t_stack	*ft_swap(t_stack *head);
void	ft_free_stack(t_stack *head);
void	ft_print_stack(t_stack *head);
int		ft_rm_bottom(t_stack *head);
int		ft_last(t_stack *head);
int		ft_length(t_stack *head);

#endif
