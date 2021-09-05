/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:24:11 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 19:25:07 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = parse_input(argc, argv);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
