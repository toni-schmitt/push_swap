/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:00:04 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/08 17:19:06 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	int	j;
	int	num;

	size = get_stack_size(*a);
	i = 0;
	while (!is_sorted(*a))
	{
		j = 0;
		while (j < size)
		{
			num = (*a)->index;
			if (((num >> i) & 1) > 0)
				*a = ra(*a, TRUE);
			else
				pb(a, b);
			j++;
		}
		i++;
		while (*b)
			pa(a, b);
	}
}
