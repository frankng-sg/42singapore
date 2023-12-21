/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/21 17:00:32 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_MSG "Error\n"
# define MAX_SIZE 2000

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_new(int val);
t_stack	*ft_pop(t_stack *head);
t_stack	*ft_pop_last(t_stack *head);
t_stack	*ft_push(t_stack *head, int val);
t_stack	*ft_push_last(t_stack *head, int val);
t_stack	*ft_rotate(t_stack *head);
t_stack	*ft_rrotate(t_stack *head);
t_stack	*ft_sort(t_stack *a, int size);
t_stack	*search(t_stack *head, int key);
t_stack	*ft_swap(t_stack *head);
void	ft_free_stack(t_stack *head);
void	ft_print_stack(t_stack *head);
void	ft_push2(t_stack **src, t_stack **dst);
int		ft_rm_bottom(t_stack *head);
int		ft_last(t_stack *head);
int		ft_length(t_stack *head);
int		find_min(int *nums, int size, int *visited);
int		has_duplicate(int *nums, int size);
int		verify_sorted(t_stack *head);
int		read_bit(int val, int bit);
int		find_max_bit(t_stack *a);
int		minabc(int a, int b, int c);

#endif
