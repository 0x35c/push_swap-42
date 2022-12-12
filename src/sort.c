/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:53:34 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/28 13:37:17 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_three(t_list **head_a)
{
	const int	a = (*head_a)->index;
	const int	b = (*head_a)->next->index;
	const int	c = (*head_a)->next->next->index;

	if (a < b && b > c && a < c)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (a > b && a < c && b < c)
		sa(head_a);
	else if (a < b && a > c && c < b)
		rra(head_a);
	else if (a > b && b < c && a > c)
		ra(head_a);
	else if (a > b && b > c && a > c)
	{
		sa(head_a);
		rra(head_a);
	}
	else
		return ;
}

void	sort_four(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			pb(head_a, head_b);
			break ;
		}
		tmp = tmp->next;
		ra(head_a);
	}
	sort_three(head_a);
	pa(head_a, head_b);
}

static int	check_b(t_list *head_b)
{
	if (head_b && head_b->next)
		if (head_b->index == 4 || head_b->index == 0)
			if (head_b->next->index == 4 || head_b->next->index == 0)
				return (1);
	return (0);
}

void	sort_five(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp)
	{
		if (tmp->index == 4 || tmp->index == 0)
			pb(head_a, head_b);
		if (check_b(*head_b))
			break ;
		tmp = tmp->next;
		ra(head_a);
	}
	sort_three(head_a);
	pa(head_a, head_b);
	if ((*head_a)->index == 0)
	{
		pa(head_a, head_b);
		ra(head_a);
	}
	else
	{
		ra(head_a);
		pa(head_a, head_b);
	}
}
