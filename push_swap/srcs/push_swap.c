/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/08 20:04:11 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*
int		error_check(int argc, char **argv)
*/

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

void		init_stack(t_struct *head_A, int argc, char **argv)
{
	int			i;
	int			n;

	head_A->next = NULL;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		add_lst_back(head_A, n);
		i++;
	}

}

int			main(int argc, char **argv)
{	
	t_struct 	*head_A;
	t_struct 	*head_B;

	//error_check(argc, argv);
	head_A = (t_struct *)malloc(sizeof(t_struct));
	head_B = (t_struct *)malloc(sizeof(t_struct));
	init_stack(head_A, argc, argv);
	return (0);
}
