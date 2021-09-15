/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:55:12 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/15 18:51:18 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	return (EXIT_SUCCESS);
}

static int	prnt_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	return (putstderr("Error\n"));
}

static void	execute_operation(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		pa(a, b, FALSE);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(a, b, FALSE);
	else if (ft_strcmp(operation, "rra\n") == 0)
		*a = rra(*a, FALSE);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		*b = rrb(*b, FALSE);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(a, b, FALSE);
	else if (ft_strcmp(operation, "ra\n") == 0)
		*a = ra(*a, FALSE);
	else if (ft_strcmp(operation, "rb\n") == 0)
		*b = rb(*b, FALSE);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(a, b, FALSE);
	else if (ft_strcmp(operation, "sa\n") == 0)
		*a = sa(*a, FALSE);
	else if (ft_strcmp(operation, "sb\n") == 0)
		*b = sb(*b, FALSE);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(a, b, FALSE);
	else
		prnt_error(a, b);
}

static void	execute_operations(t_stack **a, t_stack **b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		execute_operation(operation, a, b);
		free(operation);
		operation = get_next_line(0);
	}
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
	{
		ft_printf("OK\n");
		return (free_stacks(&a, &b));
	}
	execute_operations(&a, &b);
	if (is_sorted(a) && get_stack_size(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (EXIT_SUCCESS);
}
