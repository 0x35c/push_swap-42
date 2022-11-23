/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:53:34 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/22 10:36:35 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_bca(t_sort_list **head_a, t_sort_list **head_b)
{
	pb(head_a, head_b);
	sa(head_a);
	pa(head_a, head_b);
	sa(head_a);
}

void	sort_cab(t_sort_list **head_a, t_sort_list **head_b)
{
	sa(head_a);
	pb(head_a, head_b);
	sa(head_a);
	pa(head_a, head_b);
}

void	sort_three(t_sort_list **head_a, t_sort_list **head_b)
{
	const int	a = (*head_a)->nb;
	const int	b = (*head_a)->next->nb;
	const int	c = (*head_a)->next->next->nb;

	if (a < b && b > c && a < c)
	{
		pb(head_a, head_b);
		sa(head_a);
		pa(head_a, head_b);
	}
	else if (a > b && a < c)
		sa(head_a);
	else if (a < b && a > c)
		sort_bca(head_a, head_b);
	else if (a > b && b < c)
		sort_cab(head_a, head_b);
	else if (a > b && b > c)
	{
		sort_cab(head_a, head_b);
		sa(head_a);
	}
	else
		return ;
}
/*
void	sort_four(t_sort_list **head_a, t_sort_list **head_b)
{
	const t_sort_list	tab[4] = {(*head_a),
		(*head_a)->next,
		(*head_a)->next,
		(*head_a)->next->next->next};
	int			i;

	i = 1;
	while (i < 4)
	{
		if (tab[0]->nb < tab[i]->nb)
			tab[0]->nb = tab[i]->nb;
		i++;
	}
	tab[0];
	pb(head_a, head_b);
}*/
