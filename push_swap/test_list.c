#include <stdio.h>
#include <stdlib.h>

typedef struct	s_A
{
	int				data;
	struct s_A		*next;
}				t_A;

void	lst_add_first(t_A *node, int data)
{
	t_A	*new;

	new = (t_A*)malloc(sizeof(t_A));
	new->data = data;
	new->next = node->next;
	node->next = new;
	
}

void	lst_remove_first(t_A *node)
{
	t_A *temp;

	temp = node->next;
	node->next = temp->next;
	free(temp);
}

int		main()
{
	t_A	*head;
	t_A *curr;

	head = (t_A*)malloc(sizeof(t_A));
	head->next = NULL;

	lst_add_first(head, 10);
	lst_add_first(head, 20);
	lst_add_first(head, 30);

	lst_remove_first(head);
	curr = head->next;
	free(head);
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	return (0);
}
