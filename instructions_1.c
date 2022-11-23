/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:31 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/21 18:45:21 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	sa(t_sort_list **head_a)
{
	t_sort_list	*tmp;
	t_sort_list	*tmp1;

	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp1 = (*head_a)->next;
	(*head_a)->next = tmp;
	(*head_a)->next->next = tmp1;
	ft_printf("sa\n");
}

void	sb(t_sort_list **head_b)
{
	t_sort_list	*tmp;
	t_sort_list	*tmp1;

	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp1 = (*head_b)->next;
	(*head_b)->next = tmp;
	(*head_b)->next->next = tmp1;
	ft_printf("sb\n");
}

void	ss(t_sort_list **head_a, t_sort_list **head_b)
{
	sa(head_a);
	sb(head_b);
}

void	pa(t_sort_list **head_a, t_sort_list **head_b)
{
	t_sort_list	*a_node;

	a_node = *head_b;
	*head_b = (*head_b)->next;
	a_node->next = *head_a;
	*head_a = a_node;
	ft_printf("pa\n");
}

void	pb(t_sort_list **head_a, t_sort_list **head_b)
{
	t_sort_list	*b_node;

	b_node = *head_a;
	*head_a = (*head_a)->next;
	b_node->next = NULL;
	if (*head_b)
		b_node->next = *head_b;
	*head_b = b_node;
	ft_printf("pb\n");
}
