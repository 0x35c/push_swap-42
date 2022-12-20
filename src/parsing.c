/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:21:50 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/20 16:34:24 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strjoin_space(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	i = -1;
	j = 0;
	if (s1)
	{
		while (s1[++i])
		{
			str[j] = s1[i];
			j++;
		}
	}
	free(s1);
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = ' ';
	str[j + 1] = '\0';
	return (str);
}

t_list	*add_node(char *str, t_list *head)
{
	t_list	*tmp;
	t_list	*node;

	tmp = head;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nb = ft_atoi(str);
	free(str);
	node->next = NULL;
	if (head == NULL)
		return (node);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

t_list	*create_list(int ac, char **av)
{
	t_list	*head;
	char	*tmp;
	char	**strs;
	int		i;

	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin_space(tmp, av[i]);
		i++;
	}
	if (!ft_isnum(tmp))
		ft_exit(tmp, NOT_NB);
	strs = ft_split(tmp, ' ');
	free(tmp);
	head = NULL;
	i = 0;
	while (strs[i])
	{
		head = add_node(strs[i], head);
		i++;
	}
	free(strs);
	return (head);
}
