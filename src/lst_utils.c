/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:27:14 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/13 10:16:28 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.h"

void	ft_listadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	if (tmp->next)
		while (tmp->next)
			tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

t_list	*ft_listlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_listadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
