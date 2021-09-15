/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:41:49 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/15 18:28:35 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Reverse Shift a
 *	Shifts down all elements of stack a by 1
 *	Last element becomes first element
*/
t_stack	*rra(t_stack *a, int print_operation)
{
	t_element	*old_first;
	t_element	*tmp;
	t_element	*new_first;

	old_first = a->elements;
	tmp = old_first;
	new_first = get_last_element(a);
	a->elements = new_first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	new_first->next = old_first;
	if (print_operation)
		ft_printf("rra\n");
	a->instructions++;
	return (a);
}

/*
 *	Reverse Shift b
 *	Shifts down all elements of stack b by 1
 *	Last element becomes first element
*/
t_stack	*rrb(t_stack *b, int print_operation)
{
	t_element	*old_first;
	t_element	*tmp;
	t_element	*new_first;

	old_first = b->elements;
	tmp = old_first;
	new_first = get_last_element(b);
	b->elements = new_first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	new_first->next = old_first;
	if (print_operation)
		ft_printf("rrb\n");
	b->instructions++;
	return (b);
}

/*
 *	Reverse Shift a and b
 *	Shifts down all elements of stack a and b by 1
 *	Last element becomes first element
*/
void	rrr(t_stack **a, t_stack **b, int print_operation)
{
	*a = rra(*a, FALSE);
	*b = rrb(*b, FALSE);
	if (print_operation)
		ft_printf("rrr\n");
}
