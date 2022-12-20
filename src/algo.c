/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:44:48 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/20 16:36:08 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

t_mark	*mark_lst(t_list *head)
{
	t_mark	*marks;

	marks = ft_calloc(sizeof(t_mark), 1);
	if (!marks)
		return (NULL);
	marks->len = nb_values(head);
	marks->len_packs = marks->len / 10 + 15;
	marks->low = marks->len_packs / 2;
	marks->high = marks->len_packs;
	return (marks);
}

t_mark	*send_packs(t_list **head_a, t_list **head_b)
{
	t_mark	*marks;
	int		count;

	marks = mark_lst(*head_a);
	if (marks == NULL)
		return (NULL);
	count = 0;
	while (count < marks->len - 1)
	{
		send_split(&count, marks, head_a, head_b);
		marks->high += marks->len_packs;
		marks->low += marks->len_packs;
	}
	return (marks);
}

void	opti_max(t_list **head_a, t_list **head_b, int *count, size_t len)
{
	if (check_pos(head_b, *count) <= (int)len / 2)
	{
		if (check_pos(head_b, *count - 1) > check_pos(head_b, *count))
		{
			while ((*head_b)->index != *count)
				rb(head_b);
			pa(head_a, head_b);
			(*count)--;
		}
		else
		{
			while ((*head_b)->index != *count - 1)
				rb(head_b);
			pa(head_a, head_b);
			while ((*head_b)->index != *count)
				rb(head_b);
			pa(head_a, head_b);
			sa(head_a);
			*count -= 2;
		}
	}
	else
	{
		if (check_pos(head_b, *count - 1) < check_pos(head_b, *count))
		{
			while ((*head_b)->index != *count)
				rrb(head_b);
			pa(head_a, head_b);
			(*count)--;
		}
		else
		{
			while ((*head_b)->index != *count - 1)
				rrb(head_b);
			pa(head_a, head_b);
			while ((*head_b)->index != *count)
				rrb(head_b);
			pa(head_a, head_b);
			sa(head_a);
			*count -= 2;
		}
	}
}

void	push_sorted_packs(t_list **head_a, t_list **head_b)
{
	t_mark	*marks;
	int		count;
	size_t	len;

	marks = send_packs(head_a, head_b);
	if (marks == NULL)
		return ;
	count = marks->len - 1;
	while (*head_b && (*head_b)->next)
	{
		len = nb_values(*head_b);
		opti_max(head_a, head_b, &count, len);
	}
	if (*head_b)
		pa(head_a, head_b);
	free(marks);
}
