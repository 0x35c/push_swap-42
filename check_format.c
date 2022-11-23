/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:22:06 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/22 10:39:52 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_exit(void *elem, int flag)
{
	t_sort_list	*tmp;

	if (flag == DOUBLE || flag == SORTED)
	{
		while (((t_sort_list *)elem))
		{
			tmp = ((t_sort_list *)elem);
			elem = ((t_sort_list *)elem)->next;
			free(tmp);
		}
	}
	else if (flag == NOT_NB)
		free(elem);
	if (flag == DOUBLE || flag == NOT_NB)
		ft_printf("Error\n");
	exit(1);
}

int	isdouble(t_sort_list *head)
{
	t_sort_list	*tmp;

	while (head->next)
	{
		tmp = head->next;
		while (tmp)
		{
			if (tmp->nb == head->nb)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

int	issorted(t_sort_list *head)
{
	while (head->next)
	{
		if (head->nb > head->next->nb)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
