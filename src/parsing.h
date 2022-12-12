/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:48:44 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/12 18:52:02 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "struct.h"
# define SORTED 1
# define NOT_NB 2
# define DOUBLE 3

t_list	*create_list(int ac, char **av);
int		ft_isnum(char *str);
int		issorted(t_list *head);
int		isdouble(t_list *head);
void	ft_exit(void *elem, int flag);

#endif
