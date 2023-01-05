/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:54:03 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/05 18:27:51 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "../libft/libft.h"
# include "utils_bonus.h"

void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	ra(t_list **head_a);
void	rb(t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);
void	rra(t_list **head_a);
void	rrb(t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

#endif
