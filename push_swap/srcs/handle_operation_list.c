/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operation_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:33:24 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/05 15:13:34 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_op_list(t_oper *op)
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

void	optimize_operation(t_oper *op)
{
	while (merge_operation(op))
		;
	while (delete_operation(op))
		;
}

void	handle_operation_list(t_oper *op)
{
	optimize_operation(op);
	print_op_list(op);
}
