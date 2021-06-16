/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/10 19:48:42 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int				error_check(int argc, char **argv)
{
	return (0);
}

void			init_stack(t_struct *head_a, int argc, char **argv)
{
	int			i;
	int			n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		add_lst_back(head_a, n);
		i++;
	}
}

void			push_swap(t_struct *head_a, t_struct *head_b)
{
	pb(head_a, head_b);
	pb(head_a, head_b);
	pb(head_a, head_b);
	ss(head_a, head_b);
}

int				main(int argc, char **argv)
{
	t_struct	*head_a;
	t_struct	*head_b;

	error_check(argc, argv);
	head_a = (t_struct *)malloc(sizeof(t_struct));
	head_b = (t_struct *)malloc(sizeof(t_struct));
	head_a->next = NULL;
	head_b->next = NULL;
	init_stack(head_a, argc, argv);
	push_swap(head_a, head_b);	




	// stack 확인용
	t_struct	*curr_a;
	t_struct	*curr_b;
	
	curr_a = head_a;
	curr_b = head_b;
	while (curr_a->next != NULL)
	{
		curr_a = curr_a->next;
		printf("a: %d\n", curr_a->value);
	}
	printf("----------\n");
	
	while (curr_b->next != NULL)
	{
		curr_b = curr_b->next;
		printf("b: %d\n", curr_b->value);
	}
	return (0);
}
