/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/28 11:49:41 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void			check_stack(t_struct *head)
{
	t_struct	*temp;

	temp = head->next;
	printf("stack: ");
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

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

int				*fill_arr(t_struct *node, int *arr, int len)
{
	t_struct	*temp;
	int			index;

	temp = node->next;
	index = 0;
	arr = (int *)malloc(sizeof(int) * len);
	while (temp != NULL)
	{
		arr[index] = temp->value;
		index++;
		temp = temp->next;
	}
	return (arr);
}

int				get_partition(int *arr, int start, int end)
{
	int			pivot;
	int			i;
	int			index;
	int			temp;

	pivot = arr[end];
	index = start;
	i = start;
	while (i < end)
	{
		if (arr[i] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
		i++;
	}
	temp = arr[index];
	arr[index] = arr[end];
	arr[end] = temp;
	return (index);
}

void			quick_sort(int *arr, int start, int end)
{
	int			index;

	if (start < end)
	{
		index = get_partition(arr, start, end);
		quick_sort(arr, start, index - 1);
		quick_sort(arr, index + 1, end);
	}
}

int				check_pivot(t_struct *node, int len)
{
	t_struct	*temp;
	int			*arr;
	int			pivot;

	temp = node;
	arr = NULL;
	arr = fill_arr(node, arr, len);
	quick_sort(arr, 0, len - 1);
	pivot = arr[len / 2];
	if (len % 2 == 0)
		pivot = arr[len / 2 - 1];
	free(arr);
	return (pivot);
}

void            B_to_A(t_struct *head_a, t_struct *head_b, int n)
{
    int         rb_cnt;
    int         pa_cnt;
    int         temp;
	int			pivot;

    rb_cnt = 0;
    pa_cnt = 0;
    if (n == 1)
    {
        pa(head_a, head_b);
        return ;
    }
	pivot = check_pivot(head_b, n);
    while (n)
    {
        if (head_b->next->value > pivot)
        {
            pa(head_a, head_b);
            pa_cnt++;
        }
        else
        {
            rb(head_b);
            rb_cnt++;
        }
        n--;
    }
    temp = rb_cnt;
    while (temp)
    {
        rrb(head_b);
        temp--;
    }
	printf("B_to_A\n");
	check_stack(head_a);
	check_stack(head_b);

    A_to_B(head_a, head_b, pa_cnt);
    B_to_A(head_a, head_b, rb_cnt);
}

void            A_to_B(t_struct *head_a, t_struct *head_b, int n)
{
    int         ra_cnt;
    int         pb_cnt;
    int         temp;
	int			pivot;

    ra_cnt = 0;
    pb_cnt = 0;
    if (n == 1)
        return ;
	pivot = check_pivot(head_a, n);
    while (n)
    {
		if (head_a->next->value > pivot)
        {
            ra(head_a);
            ra_cnt++;
        }
        else
        {
            pb(head_a, head_b);
            pb_cnt++;
        }
        n--;
    }
    temp = ra_cnt;
    while (temp)
    {
        rra(head_a);
        temp--;
    }
	printf("A_to_B\n");
	check_stack(head_a);
	check_stack(head_b);
    A_to_B(head_a, head_b, ra_cnt);
    B_to_A(head_a, head_b, pb_cnt);
}

int				size_of_list(t_struct *list)
{
	int			n;
	t_struct	*temp;

	n = 0;
	temp = list;
	while (temp->next != NULL)
	{
		n++;
		temp = temp->next;
	}
	return (n);
}

void			push_swap(t_struct *head_a, t_struct *head_b)
{
	int			n;

	n = size_of_list(head_a);
	A_to_B(head_a, head_b, n);
	check_stack(head_a);
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
/*	t_struct	*curr_a;
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
	}*/
	return (0);
}
