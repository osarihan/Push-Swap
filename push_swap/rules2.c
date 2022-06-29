/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:10:48 by osarihan          #+#    #+#             */
/*   Updated: 2022/06/29 14:10:52 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*iter;

	iter = (*stack);
	while (iter->next->next != NULL)
		iter = iter->next;
	iter->next = NULL;
}

void	rra(a_stack **a)
{
	a_stack	*first;

	first = ft_lstlast(*a);
	pop(a);
	first->next = (*a);
	(*a) = first;
	write (1, "rra\n", 4);
}

void	rrb(b_stack **b)
{
	b_stack	*first;

	first = ft_lstlast(*b);
	pop(b);
	first->next = (*b);
	(*b) = first;
	write (1, "rrb\n", 4);
}

void	pb(a_stack **a, b_stack **b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	first_a = *a;
	first_b = *b;
	*a = (*a)->next;
	*b = first_a;
	(*b)->next = first_b;
	write(1, "pb\n", 3);
}

void	pa(a_stack **a, b_stack **b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	first_b = *b;
	first_a = *a;
	*b = (*b)->next;
	*a = first_b;
	(*a)->next = first_a;
	write(1, "pa\n", 3);
}
