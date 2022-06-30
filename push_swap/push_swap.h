/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:12:33 by osarihan          #+#    #+#             */
/*   Updated: 2022/06/30 19:47:08 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}a_stack, b_stack,	t_stack;

//push swap funtions
void	push(t_stack **stack, int data);
t_stack	*push_swap(char **argv, int argc);
//list utils
int		ft_lstsize(t_stack *list);
t_stack	*ft_lstlast(t_stack *list);
t_stack	*ft_lstwhere(t_stack *list, int c);
int		ft_lstdata(t_stack *list, int c);

//swap utils
void	two_swap(t_stack **stack, int b);
void	three_swap(a_stack **stack, int i, int data1, int data2);
void	three_swap_b(b_stack **stack, int i, int data1, int data2);
void	five_swap(a_stack **stack_a, b_stack **stack_b, int len, int i);
void	radix_swap(a_stack **stack_a, b_stack **stack_b, int len, int i);
//rules
void	swap(t_stack **list);
void	sa(a_stack **a);
void	sb(b_stack **b);
void	ra(a_stack **a);
void	rb(b_stack **b);
void	pop(t_stack **stack);
void	rra(a_stack **a);
void	rrb(b_stack **b);
void	pb(a_stack **a, b_stack **b);
void	pa(a_stack **a, b_stack **b);
void	ss(a_stack **a, b_stack **b);
void	rrr(a_stack **a, b_stack **b);
//index funcitons
int		min_index(t_stack *stack, int i);
void	index_push(t_stack *stack);
//control funtions
int		is_number(char **argv, int argc);
int		ft_strlen(char *argv);
int		is_uniqe(t_stack *stack);
int		is_sorted(t_stack *stack);
int		big_is_sorted(t_stack *stack);
//convert functions
t_stack	*to_int(char **argv, int argc);
int		ft_atoi(const char *argv);

#endif