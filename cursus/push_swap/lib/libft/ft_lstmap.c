/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:26 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/28 16:19:37 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_list	*do_lstmap(
	t_list *root, t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;

	node = root;
	while (lst)
	{
		node->next = (t_list *)malloc(sizeof(t_list));
		if (node->next == NULL)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		node = node->next;
		node->next = NULL;
		node->content = f(lst->content);
		lst = lst->next;
	}
	return (root);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;

	if (lst == NULL)
		return (NULL);
	root = (t_list *)malloc(sizeof(t_list));
	if (root == NULL)
		return (NULL);
	root->content = f(lst->content);
	root->next = NULL;
	lst = lst->next;
	return (do_lstmap(root, lst, f, del));
}
