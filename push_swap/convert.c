/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:03:58 by osarihan          #+#    #+#             */
/*   Updated: 2022/07/02 13:00:34 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*to_int(char **argv, int argc)
{
	t_stack	*stack;
	int		j;

	stack = NULL;
	while (--argc >= 1)
	{
		j = ft_strlen(argv[argc]);
		while (argv[argc][--j] && j >= 0)
		{
			if (argv[argc][j + 1] == '\0' && argv[argc][j] == ' ')
			{
				while (argv[argc][j] == ' ')
					j--;
			}
			while ((argv[argc][j] >= '0' && argv[argc][j] <= '9')
				|| argv[argc][j] == '-')
				j--;
			push(&stack, ft_atoi(&argv[argc][j + 1]));
			while (argv[argc][j] == ' ')
				j--;
			if (j == 0)
				push(&stack, ft_atoi(&argv[argc][j]));
		}
	}
	return (stack);
}

int	ft_atoi(const char *argv)
{
	int				i;
	int				is_negative;
	unsigned long	number;

	i = 0;
	number = 0;
	is_negative = 1;
	while (argv[i] == '\n' && argv[i] == ' ')
		i++;
	if (argv[i] == '-')
		is_negative *= -1;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		number = (number * 10) + (argv[i] - '0');
		i++;
	}
	if ((number > 2147483647 && is_negative != -1)
		|| (number > 2147483648 && is_negative == -1))
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (number * is_negative);
}
