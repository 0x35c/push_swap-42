/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:31 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/12 15:34:11 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	sa(t_list **head_a)
{
	int	tmp;

	tmp = (*head_a)->index;
	(*head_a)->index = (*head_a)->next->index;
	(*head_a)->next->index = tmp;
	tmp = (*head_a)->nb;
	(*head_a)->nb = (*head_a)->next->nb;
	(*head_a)->next->nb = tmp;
	ft_printf("sa\n");
}

void	sb(t_list **head_b)
{
	int	tmp;

	tmp = (*head_b)->index;
	(*head_b)->index = (*head_b)->next->index;
	(*head_b)->next->index = tmp;
	tmp = (*head_b)->nb;
	(*head_b)->nb = (*head_b)->next->nb;
	(*head_b)->next->nb = tmp;
	ft_printf("sb\n");
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*a_node;

	a_node  = ft_listnew((*head_b)->index);
	if ((*head_b)->next)
		*head_b = (*head_b)->next;
	a_node->next = *head_a;
	*head_a = a_node;
	ft_printf("pa\n");
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*b_node;

	b_node = ft_listnew((*head_a)->index);
	*head_a = (*head_a)->next;
	if (*head_b)
		b_node->next = *head_b;
	*head_b = b_node;
	ft_printf("pb\n");
}
