/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:03 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/02 20:35:44 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void			select_function(char *input, t_struct *head_a, t_struct *head_b, t_oper *op)
{
	if (ft_strcmp(input, "pa"))
		pa(head_a, head_b, op);
	else if (ft_strcmp(input, "pb"))
		pb(head_a, head_b, op);
	else if (ft_strcmp(input, "sa"))
		sa(head_a, op);
	else if (ft_strcmp(input, "sb"))
		sb(head_b, op);
	else if (ft_strcmp(input, "pa"))
		ss(head_a, head_b, op);
	else if (ft_strcmp(input, "ra"))
		ra(head_a, op);
	else if (ft_strcmp(input, "rb"))
		rb(head_b, op);
	else if (ft_strcmp(input, "rr"))
		rr(head_a, head_b, op);
	else if (ft_strcmp(input, "rra"))
		rra(head_a, op);
	else if (ft_strcmp(input, "rrb"))
		rrb(head_b, op);
	else if (ft_strcmp(input, "rrr"))
		rrr(head_a, head_b, op);
}

int						main(int argc, char **argv)
{
	char				*oper;
	t_struct			*head_a;
	t_struct			*head_b;
	t_oper				*op;
	
	if (error_check_before(argc, argv))
		return (write_error());
	head_a = (t_struct *)malloc(sizeof(t_struct));
	head_b = (t_struct *)malloc(sizeof(t_struct));
	op = (t_oper *)malloc(sizeof(t_oper));
	head_a->next = NULL;
	head_b->next = NULL;
	op->next = NULL;
	init_stack(head_a, argc, argv);
	if (error_check_after(head_a))
		return (write_error());
	while (get_next_line(0, &oper) > 0)
	{
		select_function(oper, head_a, head_b, op);
		free(oper);
	}
	select_function(oper, head_a, head_b, op);
	free(oper);
	t_oper *temp;
	temp = op->next;
	while (temp != NULL)
	{
		printf("%s\n", temp->operation);
		temp = temp->next;
	}
	if(already_sort(head_a))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	return (0);
}
