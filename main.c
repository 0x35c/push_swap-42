/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:22:06 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/21 21:25:14 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_sort_list	*head_a;
	t_sort_list	*head_b;
	t_sort_list	*tmp;

	head_a = NULL;
	head_b = NULL;
	tmp = NULL;
	if (ac < 2)
		return (0);
	head_a = create_list(ac, av);
	if (head_a == NULL)
		return (1);
	if (isdouble(head_a))
		ft_exit(head_a, DOUBLE);
	else if (issorted(head_a))
		ft_exit(head_a, SORTED);
	sort_three(&head_a, &head_b);
	ft_printf("\n");
	while (head_a)
	{
		tmp = head_a; 
		head_a = head_a->next;
		ft_printf("%d\n", tmp->nb);
		free(tmp);
	}
	return (0);
}
