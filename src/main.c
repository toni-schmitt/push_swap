/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:24:11 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/08 17:20:05 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	prnt_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%i\t", stack->data);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*a_head;
	t_stack	*b;

	a = parse_input(argc, argv);
	a_head = a;
	if (is_sorted(a))
	{
		ft_printf("Stack is sorted\n");
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	a_head = a;
	a = index_stack(a);
	big_sort(&a, &b);
	// prnt_stack(a);
	free_stack(&a);
	free_stack(&b);
	// system("leaks push_swap");
	// fscanf(stdin, "c");
	return (EXIT_SUCCESS);
}
