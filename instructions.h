/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:54:03 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/21 18:44:54 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "libft/libft.h"
# include "struct.h"

void	sa(t_sort_list **head_a);
void	sb(t_sort_list **head_b);
void	ss(t_sort_list **head_a, t_sort_list **head_b);
void	pa(t_sort_list **head_a, t_sort_list **head_b);
void	pb(t_sort_list **head_a, t_sort_list **head_b);
void	ra(t_sort_list **head_a);
void	rb(t_sort_list **head_b);
void	rr(t_sort_list **head_a, t_sort_list **head_b);
void	rra(t_sort_list **head_a);
void	rrb(t_sort_list **head_b);
void	rrr(t_sort_list **head_a, t_sort_list **head_b);

#endif
