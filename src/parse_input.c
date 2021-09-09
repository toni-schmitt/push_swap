/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:09:14 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 09:21:22 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_stack(t_stack *a, int element)
{
	t_element	*tmp;

	tmp = a->elements;
	while (tmp && tmp->next)
	{
		if (element == tmp->data)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

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
	int		new_data;
	int		i;

	if (!is_valid_input(argc, argv))
		putstderr("Error\n");
	i = 1;
	a = new_stack();
	while (i < argc)
	{
		new_data = ft_atoi(argv[i]);
		if (is_in_stack(a, new_data))
			putstderr("Error\n");
		stack_add_back(&a, new_stack_element(new_data));
		i++;
	}
	return (a);
}
