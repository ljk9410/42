/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/08 20:17:50 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				error_check(int argc, char **argv)
{
	return (0);
}

void			init_stack(t_struct *head_a, int argc, char **argv)
{
	int			i;
	int			n;

	head_A->next = NULL;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		add_lst_back(head_a, n);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_struct	*head_a;
	t_struct	*head_b;

	error_check(argc, argv);
	head_a = (t_struct *)malloc(sizeof(t_struct));
	head_a = (t_struct *)malloc(sizeof(t_struct));
	init_stack(head_a, argc, argv);
	return (0);
}
