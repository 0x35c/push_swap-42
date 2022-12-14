/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:33:10 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/14 14:17:42 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	check_pos(t_list **head, int index, size_t len)
{
	t_list	*tmp;
	size_t	mid;
	size_t	count;

	mid = len / 2;
	tmp = *head;
	count = 0;
	while (tmp)
	{
		if (tmp->index == index)
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
	while (*count <= marks->high)
	{
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
		if (!*head_a)
			break ;
		if (check_pos(head_a, (*head_a)->index, nb_values(*head_a)) == TOP)
			rra(head_a);
		else if (check_pos(head_a, (*head_a)->index, nb_values(*head_a)) == BOT)
			ra(head_a);
		else
			return ;
	}
}
/*
void	send_back(int *count, t_mark *marks, t_list **head_a, t_list **head_b)
{
	while (*count <= marks->low && (*head_b)->next)
	{
		if ((*head_b)->index == count)
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
		if (check_pos(head_a, (*head_a)->index, marks->len) == TOP)
			rra(head_a);
		else if (check_pos(head_a, (*head_a)->index, marks->len) == BOT)
			ra(head_a);
		else
			return ;
	}
}
void	push_bot(int *count, t_mark *marks, t_list **head_a, t_list **head_b)
{
	while (*count >= marks->low)
	{
		if ((*head_b)->index == *count)
		{
			pa(head_a, head_b);
			(*count)--;
		}
		else
			rb(head_b);
	}
}

void	push_top(int *count, t_mark *marks, t_list **head_a, t_list **head_b)
{
	while (*count >= marks->high)
	{	
		if ((*head_b)->index == *count)
		{
			pa(head_a, head_b);
			(*count)--;
		}
		else
			rrb(head_b);
	}
}
*/
