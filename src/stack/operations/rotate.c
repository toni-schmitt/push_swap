/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:41:18 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/15 18:28:00 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Shift a
 *	Shifts up all elements of stack a by 1
 *	First element becomes last element
*/
t_stack	*ra(t_stack *a, int print_operation)
{
	t_element	*tmp;
	t_element	*cpy;

	if (a->elements == NULL || a->elements->next == NULL)
		return (a);
	tmp = a->elements;
	cpy = a->elements->next;
	get_last_element(a)->next = tmp;
	tmp->next = NULL;
	a->elements = cpy;
	if (print_operation)
		ft_printf("ra\n");
	a->instructions++;
	return (a);
}

/*
 *	Shift b
 *	Shifts up all elements of stack b by 1
 *	First element becomes last element
*/
t_stack	*rb(t_stack *b, int print_operation)
{
	t_element	*tmp;
	t_element	*cpy;

	if (b->elements == NULL || b->elements->next == NULL)
		return (b);
	tmp = b->elements;
	cpy = b->elements->next;
	get_last_element(b)->next = tmp;
	tmp->next = NULL;
	b->elements = cpy;
	if (print_operation)
		ft_printf("rb\n");
	b->instructions++;
	return (b);
}

/*
 *	Shift a and b
 *	Shifts up all elements of stack a and b by 1
 *	Last element becomes first element
*/
void	rr(t_stack **a, t_stack **b, int print_operation)
{
	*a = ra(*a, FALSE);
	*b = rb(*b, FALSE);
	if (print_operation)
		ft_printf("rr\n");
}
