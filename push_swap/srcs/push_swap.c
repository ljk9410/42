/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/10 16:43:30 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int				error_check(int argc, char **argv)
{
	return (0);
}

void			add_new_node(t_struct *node)
{
	t_struct	*new;
	t_struct	*temp;

	new = (t_struct *)malloc(sizeof(t_struct));
	temp = find_lst_last(node);
	temp->next = new;
	new->next = NULL;
}

void			init_stack(t_struct *a, t_struct *b, int argc, char **argv)
{
	int			i;
	int			n;

	a->next = NULL;
	b->next = NULL;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		add_lst_back(a, n);
		add_new_node(b);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_struct	*head_a;
	t_struct	*head_b;

	error_check(argc, argv);
	head_a = (t_struct *)malloc(sizeof(t_struct));
	head_b = (t_struct *)malloc(sizeof(t_struct));
	init_stack(head_a, head_b, argc, argv);

	t_struct	*curr_a;
	t_struct	*curr_b;
	curr_a = head_a;
	curr_b = head_b;
	while (curr_a->next != NULL)
	{
		curr_a = curr_a->next;
		printf("%d\n", curr_a->value);
		printf("b: %p\n", curr_b);
		curr_b = curr_b->next;
	}
	printf("%p", curr_b->next);
	return (0);
}
