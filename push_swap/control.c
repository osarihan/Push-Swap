/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:00:32 by osarihan          #+#    #+#             */
/*   Updated: 2022/07/02 14:10:02 by osarihan         ###   ########.fr       */
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

int	is_unique(t_stack *stack)
{
	int	i;
	int	j;
	int	data1;
	int	data2;

	i = 0;
	j = 0;
	while (i < ft_lstsize(stack))
	{
		data1 = ft_lstdata(stack, i);
		while (j < ft_lstsize(stack))
		{
			if (j + 1 == ft_lstsize(stack) && i == j)
				return (1);
			if (i == j)
				j++;
			data2 = ft_lstdata(stack, j);
			if (data1 == data2)
				return (0);
			j++;
		}
		j = 0;
		i++;
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

int	big_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
