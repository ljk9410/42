/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:24:32 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/08 15:10:08 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_next;
	t_list	*curr;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((new_head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	curr = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((new_next = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr->next = new_next;
		curr = new_next;
		lst = lst->next;
	}
	return (new_head);
}
