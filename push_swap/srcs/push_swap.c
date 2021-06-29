/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/29 15:52:33 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int			n;

	n = size_of_list(head_a);
//	if (n == 2)
//		sort_two();
//	if (n == 3)
//		sort_three();
//	if (n == 5)
//		sort_five();
	a_to_b(head_a, head_b, n);
}

int				main(int argc, char **argv)
{
	t_struct	*head_a;
	t_struct	*head_b;

	if (error_check_before(argc, argv))
		return (write_error());
	head_a = (t_struct *)malloc(sizeof(t_struct));
	head_b = (t_struct *)malloc(sizeof(t_struct));
	head_a->next = NULL;
	head_b->next = NULL;
	init_stack(head_a, argc, argv);
	if (error_check_after(head_a))
		return (write_error());
	push_swap(head_a, head_b);	



	return (0);
}
