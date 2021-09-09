/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:28:34 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 09:24:20 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees stack */
void	free_stack(t_stack **stack)
{
	t_element	*element;
	t_element	*tmp;

	if (*stack == NULL)
		return ;
	element = (*stack)->elements;
	while (element)
	{
		tmp = element;
		element = element->next;
		free(tmp);
		tmp = NULL;
	}
	element = NULL;
	free(*stack);
	*stack = NULL;
}

/* Returns true if stack is sorted */
int	is_sorted(t_stack *stack)
{
	t_element	*elements;

	elements = stack->elements;
	while (elements && elements->next)
	{
		if (elements->data > elements->next->data)
			return (FALSE);
		elements = elements->next;
	}
	return (TRUE);
}

/* Returns the size of the stack */
int	get_stack_size(t_stack *stack)
{
	t_element	*elements;
	int			i;

	i = 0;
	elements = stack->elements;
	while (elements)
	{
		i++;
		elements = elements->next;
	}
	stack->size = i;
	return (i);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;

	while (stack->elements->next)
	{
		stack_add_back(&copy, new_stack_element(stack->elements->data));
		stack->elements = stack->elements->next;
	}
	return (copy);
}
