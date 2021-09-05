/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:40:45 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/01 15:54:08 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Push a
 *	Takes the first element of stack b and pushes it to stack a
*/
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL || *b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n");
}

/*
 *	Push b
 *	Takes the first element of stack a and pushes it to stack b
*/
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL || *b == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
}
