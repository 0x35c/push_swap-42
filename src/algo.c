/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:44:48 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/12 15:45:49 by ulayus           ###   ########.fr       */
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
	while (count < marks->len && (*head_a)->next)
	{
		send_split(&count, marks, head_a, head_b);
		marks->high += marks->len_packs;
		marks->low += marks->len_packs;
	}
	return (marks);
}

# include <sys/types.h>

void	push_sorted_packs(t_list **head_a, t_list **head_b)
{
	t_mark	*marks;
	int		count;
	t_list	*tmpa = *head_a;
	t_list	*tmpb = *head_b;

	marks = send_packs(head_a, head_b);
	if (marks == NULL)
		return ;
	count = marks->len - 2;
	while (count && tmpb->next && tmpa->next)
    {            
        if ((*head_b)->index == count)
        {           
            pa(head_a, head_b);
            count--;
        }           
		else
		{
			usleep(8000);
			ft_printf("Index_b: %d\n", (*head_b)->index);
			ft_printf("Index_a: %d\n", (*head_a)->index);
			tmpa = tmpa->next;
			tmpb = tmpb->next;
			/*
			if (check_pos(head_b, count, marks->len) == TOP)
			{
				ft_printf("TOP\n");
			}
			else if (check_pos(head_b, count, marks->len) == BOT)
			{
				rb(head_b);
				ft_printf("BOT\n");
			}
			*/
		}
    }
	/*
		marks->high -= marks->len_packs;
		push_top(&count, marks, head_a, head_b);	
		push_bot(&count, head_a, head_b);	
		marks->low -= marks->len_packs;
	}
	*/
}
