/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:43:21 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/21 18:44:37 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	ra(t_sort_list **head_a)
{
	t_sort_list	*lst;
	t_sort_list	*tmp;

	tmp = *head_a;
	lst = *head_a;
	*head_a = (*head_a)->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	lst->next->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_sort_list **head_b)
{
	t_sort_list	*lst;
	t_sort_list	*tmp;

	tmp = *head_b;
	lst = *head_b;
	*head_b = (*head_b)->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	lst->next->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_sort_list **head_a, t_sort_list **head_b)
{
	ra(head_a);
	rb(head_b);
}

void	rra(t_sort_list **head_a)
{
	t_sort_list	*lst;
	t_sort_list	*tmp;

	lst = *head_a;
	while (lst->next->next)
		lst = lst->next;
	tmp = *head_a;
	lst->next->next = *head_a;
	*head_a = lst->next;
	lst->next = NULL;
	ft_printf("ra\n");
}

void	rrb(t_sort_list **head_b)
{
	t_sort_list	*lst;
	t_sort_list	*tmp;

	lst = *head_b;
	while (lst->next->next)
		lst = lst->next;
	tmp = *head_b;
	lst->next->next = *head_b;
	*head_b = lst->next;
	lst->next = NULL;
	ft_printf("rb\n");
}
