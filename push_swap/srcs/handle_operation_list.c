/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operation_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:33:24 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/02 16:13:10 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ft_strcmp(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		return (0);
	return (1);
}

int				return_merge_case(t_oper *op)
{
	t_oper		*temp;

	temp = op->next;
	if (ft_strcmp(temp->operation, "ra") && ft_strcmp(temp->next->operation, "rb"))
		return (1);
	if (ft_strcmp(temp->operation, "rb") && ft_strcmp(temp->next->operation, "ra"))
		return (1);
	if (ft_strcmp(temp->operation, "sa") && ft_strcmp(temp->next->operation, "sb"))
		return (2);
	if (ft_strcmp(temp->operation, "sb") && ft_strcmp(temp->next->operation, "sa"))
		return (2);
	if (ft_strcmp(temp->operation, "rra") && ft_strcmp(temp->next->operation, "rrb"))
		return (3);
	if (ft_strcmp(temp->operation, "rrb") && ft_strcmp(temp->next->operation, "rra"))
		return (3);
	return (0);
}

int				return_delete_case(t_oper *op)
{
	t_oper		*temp;

	temp = op->next;
	if (ft_strcmp(temp->operation, "pa") && ft_strcmp(temp->next->operation, "pb"))
		return (1);
	if (ft_strcmp(temp->operation, "pb") && ft_strcmp(temp->next->operation, "pa"))
		return (1);
	if (ft_strcmp(temp->operation, "sa") && ft_strcmp(temp->next->operation, "sa"))
		return (1);
	if (ft_strcmp(temp->operation, "sb") && ft_strcmp(temp->next->operation, "sb"))
		return (1);
	if (ft_strcmp(temp->operation, "ra") && ft_strcmp(temp->next->operation, "rra"))
		return (1);
	if (ft_strcmp(temp->operation, "rra") && ft_strcmp(temp->next->operation, "ra"))
		return (1);
	if (ft_strcmp(temp->operation, "rb") && ft_strcmp(temp->next->operation, "rrb"))
		return (1);
	if (ft_strcmp(temp->operation, "rrb") && ft_strcmp(temp->next->operation, "rb"))
		return (1);
	if (ft_strcmp(temp->operation, "rr") && ft_strcmp(temp->next->operation, "rrr"))
		return (1);
	return (0);
}

void			print_op_list(t_oper *op)
{
	t_oper		*temp;

	temp = op->next;

	while (temp != NULL)
	{
		if (temp->operation != NULL)
		{
			write(1, temp->operation, ft_strlen(temp->operation));
			write(1, "\n", 1);
		}
		temp = temp->next;
	}
}

t_oper *		create_op_list_node(char *oper)
{
	t_oper		*res;

	res = (t_oper *)malloc(sizeof(t_oper));
	res->operation = ft_strdup(oper);
	res->next = NULL;
	return (res);
}

void			delete_op_list_in_middle(t_oper *op, int num)
{
	t_oper		*temp;
	t_oper		*temp_op_node;
	int			index;

	index = 1;
	temp = op->next;
	if (num == 1)
	{
		free(temp->operation);
		free(temp);
		op->next = NULL;
		return ;
	}
	while (temp != NULL && index < num - 1)
	{
		temp = temp->next;
		index++;
	}
	temp_op_node = temp->next;
	temp->next = temp_op_node->next;
	free(temp_op_node->operation);
	free(temp_op_node);
}

void			add_op_list_in_middle(t_oper *op, t_oper *node, int num)
{
	t_oper		*temp;
	t_oper		*temp_op_node;
	int			index;

	index = 1;
	temp = op->next;
	if (num == 1)
	{
		temp = node;
		return ;
	}
	while (temp != NULL && index < num - 1)
	{
		temp = temp->next;
		index++;
	}
	temp_op_node = temp->next;
	temp->next = node;
	node->next = temp_op_node;
}

int				merge_operation(t_oper *op)
{
	int			merge_case;
	int			index;
	t_oper		*temp;
	t_oper		*added_node;

	index = 1;
	temp = op->next;
	while (temp->next != NULL)
	{
		if ((merge_case = return_merge_case(temp)))
		{
			delete_op_list_in_middle(op, index);
			delete_op_list_in_middle(op, index);
			if (merge_case == 1)
				added_node = create_op_list_node("rr");
			if (merge_case == 2)
				added_node = create_op_list_node("ss");
			if (merge_case == 3)
				added_node = create_op_list_node("rrr");
			add_op_list_in_middle(op, added_node, index);
			return (1);
		}
		else
			temp = temp->next;
		index++;
	}
	return (0);
}

int				delete_operation(t_oper *op)
{
	t_oper		*temp;
	int			index;

	temp = op->next;
	index = 1;
	while (temp->next != NULL)
	{
		if (return_delete_case(temp))
		{
			temp = temp->next->next;
			delete_op_list_in_middle(op, index);
			delete_op_list_in_middle(op, index);
			return (1);
		}
		else
		{
			temp = temp->next;
			index++;
		}
	}
	return (0);
}

void			optimize_operation(t_oper *op)
{
	while (merge_operation(op))
		;
	while (delete_operation(op))
		;
}


void			handle_operation_list(t_oper *op)
{
	optimize_operation(op);
	
	print_op_list(op);
}
