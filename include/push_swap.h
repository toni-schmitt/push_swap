/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:23:45 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 13:45:22 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_element
{
	int					data;
	int					index;
	struct s_element	*next;
}	t_element;

typedef struct s_stack
{
	int			size;
	int			instructions;
	t_element	*head;
	t_element	*elements;
}	t_stack;

/* PARSE_INPUT */
t_stack		*parse_input(int argc, char *argv[]);

/* STACK */
t_stack		*new_stack(void);
t_element	*new_stack_element(int data);
void		stack_add_back(t_stack **stack, t_element *new);
void		stack_add_front(t_stack **stack, t_element *new);
t_element	*get_last_element(t_stack *stack);
int			is_sorted(t_stack *stack);
void		free_stack(t_stack **stack);
int			get_stack_size(t_stack *stack);
t_stack		*copy_stack(t_stack *stack);

/* OPERATIONS */
t_stack		*sa(t_stack *a, int print_operation);
t_stack		*sb(t_stack *b, int print_operation);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
t_stack		*ra(t_stack *a, int print_operation);
t_stack		*rb(t_stack *b, int print_operation);
void		rr(t_stack **a, t_stack **b);
t_stack		*rra(t_stack *a, int print_operation);
t_stack		*rrb(t_stack *b, int print_operation);
void		rrr(t_stack **a, t_stack **b);

/* SORTING */
void		big_sort(t_stack **a, t_stack **b);
void		small_sort(t_stack **a, t_stack **b);
void		very_small_sort(t_stack **a, t_stack **b);
/* INDEXING */
int			*quickSort(t_stack *stack);
t_stack		*index_stack(t_stack *stack);

#endif