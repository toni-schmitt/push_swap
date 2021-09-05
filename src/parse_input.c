/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:09:14 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/02 14:06:34 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (FALSE);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_issign(argv[i][j]))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_stack	*parse_input(int argc, char *argv[])
{
	t_stack	*a;
	int		i;

	if (!is_valid_input(argc, argv))
		putstderr("Error\n");
	i = 1;
	while (i < argc)
	{
		if (stack_add_back(&a, new_stack_element(ft_atoi(argv[i]))) == FALSE)
			putstderr("Error\n");
		i++;
	}
	return (a);
}
