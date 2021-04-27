/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:23:38 by jung-lee          #+#    #+#             */
/*   Updated: 2020/11/07 12:57:09 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	curr = *lst;
	if (curr == NULL || del == NULL)
		return ;
	while (curr)
	{
		temp = curr->next;
		ft_lstdelone(curr, del);
		curr = temp;
	}
	*lst = NULL;
}
