/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:41:49 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/02 14:03:54 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Reverse Shift a
 *	Shifts down all elements of stack a by 1
 *	First element become last one
*/
t_stack	*rra(t_stack *a, int print_operation)
{
	t_stack	*tmp;
	t_stack	*cpy;

	if (a == NULL || a->next == NULL)
		return (a);
	tmp = a;
	cpy = a->next;
	get_last_element(a)->next = tmp;
	tmp->next = NULL;
	a = cpy;
	if (print_operation)
		ft_printf("rra\n");
	return (a);
}

/*
 *	Reverse Shift b
 *	Shifts down all elements of stack b by 1
 *	First element become last one
*/
t_stack	*rrb(t_stack *b, int print_operation)
{
	t_stack	*tmp;
	t_stack	*cpy;

	if (b == NULL || b->next == NULL)
		return (b);
	tmp = b;
	cpy = b->next;
	get_last_element(b)->next = tmp;
	tmp->next = NULL;
	b = cpy;
	if (print_operation)
		ft_printf("rrb\n");
	return (b);
}

/*
 *	Reverse Shift a and b
 *	Shifts down all elements of stack a and b by 1
 *	First element become last one
*/
void	rrr(t_stack **a, t_stack **b)
{
	*a = rra(*a, FALSE);
	*b = rrb(*b, FALSE);
	ft_printf("rrr\n");
}
