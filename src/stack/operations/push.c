/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:40:45 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/15 18:29:36 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Push a
 *	Takes the first element of stack b and pushes it to stack a
*/
void	pa(t_stack **a, t_stack **b, int print_operation)
{
	t_element	*tmp;

	if ((*b)->elements == NULL)
		(*b)->elements = new_stack_element(0);
	tmp = (*b)->elements;
	(*b)->elements = (*b)->elements->next;
	tmp->next = (*a)->elements;
	(*a)->elements = tmp;
	if (print_operation)
		ft_printf("pa\n");
	(*a)->instructions++;
}

/*
 *	Push b
 *	Takes the first element of stack a and pushes it to stack b
*/
void	pb(t_stack **a, t_stack **b, int print_operation)
{
	t_element	*tmp;

	if ((*a)->elements == NULL)
		(*a)->elements = new_stack_element(0);
	tmp = (*a)->elements;
	(*a)->elements = (*a)->elements->next;
	tmp->next = (*b)->elements;
	(*b)->elements = tmp;
	if (print_operation)
		ft_printf("pb\n");
	(*a)->instructions++;
}
