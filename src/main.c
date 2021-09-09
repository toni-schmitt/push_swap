/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:24:11 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 10:08:36 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*a_head;
	t_stack	*b;

	a = parse_input(argc, argv);
	a->size = get_stack_size(a);
	b = new_stack();
	a_head = a;
	if (is_sorted(a))
	{
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	a_head = a;
	a = index_stack(a);
	if (a->size > 10)
		big_sort(&a, &b);
	else
		small_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (EXIT_SUCCESS);
}
