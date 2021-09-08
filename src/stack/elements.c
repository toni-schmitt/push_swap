/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:29:04 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/08 17:10:20 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = 0;
	new->index = 0;
	new->next = NULL;
	return (new);
}

/* Returns a pointer to the last element of stack */
t_stack	*get_last_element(t_stack *stack)
{
	t_stack	*stack_cpy;

	stack_cpy = stack;
	while (stack_cpy->next)
		stack_cpy = stack_cpy->next;
	return (stack_cpy);
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
