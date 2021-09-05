/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:39:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/01 15:53:48 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
 *	Swap a
 *	Swaps 2 first elements of stack a
 *	Does nothing if there are less then 2 elements in stack
 *	Returnes swapped stack 
 */
t_stack	*sa(t_stack *a, int print_operation)
{
	if (a == NULL)
		return (NULL);
	if (print_operation)
		ft_printf("sa\n");
	if (a->next)
		swap(&a->data, &a->next->data);
	return (a);
}

/*
 *	Swap b
 *	Swaps 2 first elements of stack b
 *	Does nothing if there are less then 2 elements in stack
 *	Returnes swapped stack 
 */
t_stack	*sb(t_stack *b, int print_operation)
{
	if (b == NULL)
		return (NULL);
	if (print_operation)
		ft_printf("sb\n");
	if (b->next)
		swap(&b->data, &b->next->data);
	return (b);
}

/* 
 *	Swap a and b
 *	Swaps 2 first elements of stack a and b
 */
void	ss(t_stack **a, t_stack **b)
{
	*a = sa(*a, FALSE);
	*b = sb(*b, FALSE);
	ft_printf("ss\n");
}
