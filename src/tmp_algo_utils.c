/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:33:10 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/13 10:59:51 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	check_pos(t_list **head, t_mark *marks)
{
	t_list	*tmp;
	size_t	mid;
	size_t	count;

	mid = marks->len / 2;
	tmp = *head;
	count = 0;
	while (tmp)
	{
		if (tmp->index < marks->high)
		{
			if (count < mid)
				return (TOP);
			else
				return (BOT);
		}
		count++;
		tmp = tmp->next;
	}
	return (NOT_FOUND);
}

void	send_split(int *count, t_mark *marks, t_list **head_a, t_list **head_b)
{
	while ((*count < marks->high && (*head_a)->next))
	{
		ft_printf("Count: %d, index: %d\n", *count, (*head_a)->index);
		if ((*head_a)->index <= marks->low)
		{
			pb(head_a, head_b);
			(*count)++;
		}
		else if ((*head_a)->index <= marks->high)
		{
			pb(head_a, head_b);
			rb(head_b);
			(*count)++;
		}
		if (check_pos(head_a, marks) == TOP)
			rra(head_a);
		else if (check_pos(head_a, marks) == BOT)
			ra(head_a);
	}
}
/*
void	push_bot(int *count, t_list **head_a, t_list **head_b)
{
	while (*count)
	{
		if (check_pos(head_b, (*head_b)->index) == TOP)
			rrb(head_a);
		else if (check_pos(head_b, (*head_b)->index) == BOT)
			rb(head_a);
		else
			return ;
		if ((*head_b)->index == *count)
		{
			pa(head_a, head_b);
			(*count)--;
		}
	}
}

void	push_top(int *count, t_mark *marks, t_list **head_a, t_list **head_b)
{
	while (*count >= marks->high)
	{	
		rrb(head_b);
		if ((*head_b)->index >= marks->low)
		{
			pa(head_a, head_b);
			(*count)--;
		}
	}
}*/
