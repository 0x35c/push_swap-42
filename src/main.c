/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:22:06 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/14 13:21:06 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tmp;

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
	add_index(&head_a);
	push_sorted_packs(&head_a, &head_b);
	//sort_five(&head_a, &head_b);
	//sort_three(&head_a);
	ft_printf("\n");
	while (head_a)
	{
		tmp = head_a; 
		head_a = head_a->next;
		//ft_printf("A: value: %d, index:%d\n", tmp->nb, tmp->index);
		free(tmp);
	}
	while (head_b)
	{
		tmp = head_b; 
		head_b = head_b->next;
		//ft_printf("B: value: %d, index:%d\n", tmp->nb, tmp->index);
		free(tmp);
	}
	return (0);
}
