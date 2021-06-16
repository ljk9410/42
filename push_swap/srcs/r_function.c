#include "../includes/push_swap.h"

void			ra(t_struct *head_a)
{
	t_struct	*temp;
	t_struct	*last;

	if ((head_a->next != NULL) && (head_a->next->next != NULL))
	{
		temp = head_a->next;
		last = find_lst_last(head_a);
		head_a->next = temp->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void			rb(t_struct *head_b)
{
	t_struct	*temp;
	t_struct	*last;

	if ((head_b->next != NULL) && (head_b->next->next != NULL))
	{
		temp = head_b->next;
		last = find_lst_last(head_b);
		head_b->next = temp->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void			rr(t_struct *head_a, t_struct *head_b)
{
	ra(head_a);
	rb(head_b);
}
