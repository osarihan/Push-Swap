/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:11:29 by osarihan          #+#    #+#             */
/*   Updated: 2022/06/29 13:50:25 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, int data)
{
	t_stack	*value;

	value = (t_stack *)malloc(sizeof(t_stack));
	if (!value)
		return ;
	value->content = data;
	value->next = NULL;
	if (!stack)
	{
		(*stack) = value;
		return ;
	}
	value->next = (*stack);
	(*stack) = value;
}

t_stack	*push_swap(char **argv, int argc)
{
	a_stack	*stack_a;
	b_stack	*stack_b;
	int		len;

	stack_b = NULL;
	stack_a = to_int(argv, argc);
	len = ft_lstsize(stack_a);
	index_push(stack_a);
	if (len <= 3)
		three_swap(&stack_a, 0, 0, 0);
	else if (len <= 5)
		five_swap(&stack_a, &stack_b, len, 0);
	else
		radix_swap(&stack_a, &stack_b, len, 0);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		len;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		write (2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	if (argc > 1)
	{
		if (is_number(argv, argc))
		{
			stack = push_swap(argv, argc);
			len = ft_lstsize(stack);
		}
		else
		{
			write(2, "Error\n", 6);
			free(stack);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
