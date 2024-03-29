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
	while (1)
	{
		if (merge_operation(op) == 0)
			break ;
	}
	while (1)
	{
		if (delete_operation(op) == 0)
			break ;
	}
}

void	handle_operation_list(t_oper *op)
{
	optimize_operation(op);
	print_op_list(op);
}
