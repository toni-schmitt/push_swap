/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:29:04 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 13:45:36 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->size = 0;
	new->elements = NULL;
	new->head = new->elements;
	new->instructions = 0;
	return (new);
}

/* Returns a pointer to the last element of stack */
t_element	*get_last_element(t_stack *stack)
{
	t_element	*first;

	first = stack->elements;
	while (first->next)
		first = first->next;
	return (first);
}

void	stack_add_front(t_stack **stack, t_element *new)
{
	t_element	*tmp;

	if (new == NULL || *stack == NULL)
		return ;
	tmp = (*stack)->elements;
	(*stack)->elements = (*stack)->elements->next;
	tmp->next = new;
	new = tmp;
}

void	stack_add_back(t_stack **stack, t_element *new)
{
	if (new == NULL)
		return ;
	if ((*stack)->elements == NULL)
	{
		(*stack)->elements = new;
		return ;
	}
	get_last_element(*stack)->next = new;
}

t_element	*new_stack_element(int data)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->next = NULL;
	return (new);
}
