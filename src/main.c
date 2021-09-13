/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:24:11 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/13 17:15:18 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = new_stack();
	parse_input(&a, argc, argv);
	a->size = get_stack_size(a);
	a->head = a->elements;
	b = new_stack();
	b->size = get_stack_size(b);
	b->head = b->elements;
	if (is_sorted(a))
		return (free_stacks(&a, &b));
	a = index_stack(a);
	if (a->size >= 10)
		big_sort(&a, &b);
	else if (a->size > 3)
		small_sort(&a, &b);
	else if (a->size <= 3)
		very_small_sort(&a);
	return (free_stacks(&a, &b));
}
