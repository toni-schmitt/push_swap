/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:09:14 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/14 16:37:49 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

static int	is_valid_input(char *argv)
{
	long	lnbr;

	lnbr = ft_atol(argv);
	if (lnbr < INT_MIN || lnbr > INT_MAX || ft_strlen(argv) > 11)
		return (FALSE);
	while (*argv)
	{
		if (ft_issign(*argv))
			argv++;
		if (!ft_isdigit(*argv))
			return (FALSE);
		argv++;
	}
	return (TRUE);
}

static int	prnt_error(char **split, t_stack **a)
{
	free_stack(a);
	ft_free_split(split);
	return (putstderr("Error\n"));
}

static int	check(char **split, t_stack **a, char *nbr)
{
	int	new_digit;

	if (!is_valid_input(nbr))
		prnt_error(split, a);
	new_digit = ft_atoi(nbr);
	if (is_in_stack(*a, new_digit))
		prnt_error(split, a);
	return (new_digit);
}

void	parse_input(t_stack **a, int argc, char *argv[])
{
	char	**split;
	int		i;
	int		j;
	int		new_digit;

	split = NULL;
	if (argc < 2)
		prnt_error(split, a);
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			prnt_error(split, a);
		j = 0;
		while (split[j])
		{
			new_digit = check(split, a, split[j]);
			stack_add_back(a, new_stack_element(new_digit));
			j++;
		}
		ft_free_split(split);
		i++;
	}
}
