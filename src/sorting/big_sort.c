/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:00:04 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 10:08:08 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (!is_sorted(*a))
	{
		j = 0;
		while (j < (*a)->size)
		{
			num = (*a)->elements->index;
			if (((num >> i) & 1) > 0)
				*a = ra(*a, TRUE);
			else
				pb(a, b);
			j++;
		}
		i++;
		while ((*b)->elements)
			pa(a, b);
	}
}
