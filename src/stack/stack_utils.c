/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:28:34 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 19:28:52 by tschmitt         ###   ########.fr       */
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
