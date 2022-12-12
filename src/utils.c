/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:23:19 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/04 14:32:48 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	nb_values(t_list *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

int	*sort_int_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
			 	tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
