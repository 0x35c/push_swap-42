/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:40:27 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/02 23:35:51 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exit_error(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	ft_exit(NULL, INVALID);
}

int	ft_isnum(char *str)
{
	int	i;
	int	sign;

	sign = 0;
	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (sign && (str[1] > '9' || str[1] < '0'))
		return (0);
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && !ft_isspace(str[i]) && !sign)
			return (0);
		else if (!sign && (str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '0')
			count++;
		i++;
	}
	if (count > 12 || ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

void	check_format(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!check_int(strs[i]) || !ft_isnum(strs[i]) || isempty(strs[i]))
			exit_error(strs);
		i++;
	}
}
