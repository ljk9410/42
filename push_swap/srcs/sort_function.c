#include "../includes/push_swap.h"

int	find_max(t_struct *head)
{
	int			max;
	t_struct	*temp;

	temp = head->next;
	max = temp->value;
	while (temp != NULL)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_struct *head)
{
	int			min;
	t_struct	*temp;

	temp = head->next;
	min = temp->value;
	while (temp != NULL)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

void	sort_two_a(t_struct *head_a, t_oper *op)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	temp_up = head_a->next;
	temp_down = temp_up->next;
	if (temp_up->value > temp_down->value)
		sa(head_a, op);
}

void	sort_two_b(t_struct *head_b, t_oper *op)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	temp_up = head_b->next;
	temp_down = temp_up->next;
	if (temp_up->value < temp_down->value)
		sb(head_b, op);
}

void	sort_three_a(t_struct *head_a, t_oper *op)
{
	int			max;
	t_struct	*temp;

	temp = head_a->next;
	max = find_max(head_a);
	while (temp->value != max)
		temp = temp->next;
	//최대값이 마지막에 있을 때
	if (temp->next == NULL)
		sort_two_a(head_a, op);
	//최대값이 두 번째에 있을 때
	else if (temp->next->next == NULL)
	{
		rra(head_a, op);
		sort_two_a(head_a, op);
	}
	//최대값이 제일 위에 있을 때
	else
	{
		ra(head_a, op);
		sort_two_a(head_a, op);
	}
}

void	sort_three_b(t_struct *head_b, t_oper *op)
{
	int			min;
	t_struct	*temp;

	temp = head_b->next;
	min = find_min(head_b);
	while (temp->value != min)
		temp = temp->next;
	if (temp->next == NULL)
		sort_two_b(head_b, op);
	else if (temp->next->next == NULL)
	{
		rrb(head_b, op);
		sort_two_b(head_b, op);
	}
	else
	{
		rb(head_b, op);
		sort_two_b(head_b, op);
	}
}

void	check_list(t_struct *node)
{
	t_struct *temp;

	temp = node->next;
	printf("list: ");
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

void	sort_five(t_struct *head_a, t_struct *head_b, int len, t_oper *op)
{
	int			middle;
	int			i;
	
	i = len;
	middle = check_pivot(head_a, len);
	while (i--)
	{
		if (head_a->next->value < middle)
			pb(head_a, head_b, op);
		else
			ra(head_a, op);
	}
	sort_three_a(head_a, op);
	sort_two_b(head_b, op);
	pa(head_a, head_b, op);
	pa(head_a, head_b, op);
}
