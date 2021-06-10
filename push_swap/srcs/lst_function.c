/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:43:39 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/10 16:45:24 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct	*find_lst_last(t_struct *node)
{
	t_struct	*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void		add_lst_back(t_struct *node, int n)
{
	t_struct	*new;
	t_struct	*temp;

	new = (t_struct *)malloc(sizeof(t_struct));
	temp = find_lst_last(node);
	temp->next = new;
	new->value = n;
	new->next = NULL;
}

void		add_new_node(t_struct *node)
{
}
