/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:39:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 13:46:51 by tschmitt         ###   ########.fr       */
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
	if (a->elements == NULL)
		return (NULL);
	if (print_operation)
		ft_printf("sa\n");
	if (a->elements->next)
		swap(&a->elements->data, &a->elements->next->data);
	a->instructions++;
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
	if (b->elements == NULL)
		return (NULL);
	if (print_operation)
		ft_printf("sb\n");
	if (b->elements->next)
		swap(&b->elements->data, &b->elements->next->data);
	b->instructions++;
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
