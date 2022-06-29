/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:00:32 by osarihan          #+#    #+#             */
/*   Updated: 2022/06/29 14:01:23 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char **argv, int argc)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t')
				k = 0;
			while ((argv[i][j] == '-' || argv[i][j] == '+') && ++j)
				k++;
			if (((argv[i][j] != '-') && (argv[i][j] < '0' || argv[i][j] > '9')
						&& (argv[i][j] != 32 && argv[i][j] != '\t')) || k > 1)
				return (0);
			j++;
		}
		i++;
		k = 0;
	}
	return (1);
}

int	ft_strlen(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	is_uniqe(t_stack *stack)
{
	int		data;
	t_stack	*swap;

	swap = stack;
	data = swap->content;
	while (stack && stack->next != NULL)
	{
		if (stack->next != NULL && data == stack->next->content)
			return (0);
		else if (stack->next == NULL)
		{
			swap = swap->next;
			data = swap->content;
			stack = swap;
		}
		else
			stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
