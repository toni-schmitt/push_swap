/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:15:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/01 21:23:46 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees stack */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
	*stack = NULL;
}

/* Returns true if stack is sorted */
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

/* Returns the size of the stack */
int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/* Returns a pointer to the last element of stack */
t_stack	*get_last_element(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (new == NULL || stack == NULL)
		return (FALSE);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = new;
	new = tmp;
	return (TRUE);
}

int	stack_add_back(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return (FALSE);
	if (*stack == NULL)
	{
		*stack = new;
		return (TRUE);
	}
	get_last_element(*stack)->next = new;
	return (TRUE);
}

t_stack	*new_stack_element(int data)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
