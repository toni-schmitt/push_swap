/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:23:45 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/02 14:04:19 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

/* PARSE_INPUT */
t_stack	*parse_input(int argc, char *argv[]);

/* STACK */
t_stack	*new_stack_element(int data);
int		stack_add_back(t_stack **stack, t_stack *new);
int		stack_add_front(t_stack **stack, t_stack *new);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*get_last_element(t_stack *stack);
int		get_stack_size(t_stack *stack);

/* OPERATIONS */
t_stack	*sa(t_stack *a, int print_operation);
t_stack	*sb(t_stack *b, int print_operation);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
t_stack	*ra(t_stack *a, int print_operation);
t_stack	*rb(t_stack *b, int print_operation);
void	rr(t_stack **a, t_stack **b);
t_stack	*rra(t_stack *a, int print_operation);
t_stack	*rrb(t_stack *b, int print_operation);
void	rrr(t_stack **a, t_stack **b);

#endif