/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:52:46 by osarihan          #+#    #+#             */
/*   Updated: 2022/06/30 20:28:26 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_swap(t_stack **stack, int b)
{
	if (ft_lstsize(*stack) == 1)
		exit (0);
	if (b == 0)
	{
		if (ft_lstdata(*stack, 0) > ft_lstdata(*stack, 1))
			sa(stack);
		else
			return ;
	}
	else
	{
		if (ft_lstdata(*stack, 0) < ft_lstdata(*stack, 1))
			sb(stack);
		else
			return ;
	}
}

void	three_swap(a_stack **stack, int i, int data1, int data2)
{
	int	data3;

	if (ft_lstsize(*stack) <= 2)
		two_swap(stack, 0);
	else
	{
		while (i < 3)
		{
			data1 = ft_lstwhere(*stack, 0)->index;
			data2 = ft_lstwhere(*stack, 1)->index;
			data3 = ft_lstwhere(*stack, 2)->index;
			if (data1 < data2 && data1 > data3)
				rra(stack);
			else if (data1 > data2 && data1 > data3)
				ra(stack);
			else if (data1 > data2 && data1 < data3)
				sa(stack);
			else if (data1 < data2 && data3 < data2)
			{
				sa(stack);
				ra(stack);
			}
			i++;
		}
	}
}

void	three_swap_b(b_stack **stack, int i, int data1, int data2)
{
	int	data3;

	if (ft_lstsize(*stack) == 2)
		two_swap(stack, 1);
	else
	{
		while (i < 3)
		{
			data1 = ft_lstwhere(*stack, 0)->index;
			data2 = ft_lstwhere(*stack, 1)->index;
			data3 = ft_lstwhere(*stack, 2)->index;
			if (data1 < data2 && data1 < data3)
				rb(stack);
			else if (data3 > data2 && data3 > data1)
				rrb(stack);
			else if (data1 < data2 && data1 > data3)
				sb(stack);
			else if (data2 < data1 && data2 < data3)
			{
				sb(stack);
				rb(stack);
			}
			i++;
		}
	}
}

void	five_swap(a_stack **stack_a, b_stack **stack_b, int len, int i)
{
	int	data1;
	int	data2;
	int	j;

	j = 0;
	while (i < len * 1.5)
	{	
		data1 = ft_lstwhere(*stack_a, 0)->index;
		data2 = ft_lstwhere(*stack_a, 1)->index;
		if (data1 <= len - 3 && ft_lstsize(*stack_a) > 2 && j++)
			pb(stack_a, stack_b);
		else if (data1 > len - 3 && ft_lstsize(*stack_a) != 2)
			ra(stack_a);
		else if (ft_lstsize(*stack_a) == 2 && data1 > data2)
			sa(stack_a);
		i++;
	}
	if (ft_lstsize(*stack_b) >= 2)
	{
		three_swap_b(stack_b, 0, 0, 0);
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
	}
}

void	radix_swap(a_stack **stack_a, b_stack **stack_b, int len, int i)
{
	int	data1;
	int	j;

	j = 0;
	while (is_sorted(*stack_a) == 0)
	{
		j = 0;
		while (j < len)
		{
			data1 = ft_lstwhere(*stack_a, 0)->index;
			if (((data1 >> i) & 1) == 1)
			{
				ra(stack_a);
			}
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
