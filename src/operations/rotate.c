/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:41:18 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/01 21:34:57 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Shift a
 *	Shifts up all elements of stack a by 1
 *	Last element becomes first element
*/
t_stack	*ra(t_stack *a, int print_operation)
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
		ft_printf("ra\n");
	return (a);
}

/*
 *	Shift b
 *	Shifts up all elements of stack b by 1
 *	Last element becomes first element
*/
t_stack	*rb(t_stack *b, int print_operation)
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
		ft_printf("rb\n");
	return (b);
}

/*
 *	Shift a and b
 *	Shifts up all elements of stack a and b by 1
 *	Last element becomes first element
*/
void	rr(t_stack **a, t_stack **b)
{
	*a = ra(*a, FALSE);
	*b = rb(*b, FALSE);
	ft_printf("rr\n");
}
