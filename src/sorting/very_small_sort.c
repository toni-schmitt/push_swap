/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:43:29 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 18:26:19 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	very_small_sort(t_stack **a, t_stack **b)
{
	(void)b;
	while (!is_sorted(*a))
	{
		if (!is_sorted(*a) && \
			(*a)->elements->data > (*a)->elements->next->data)
			*a = sa(*a, TRUE);
		if (!is_sorted(*a) && \
			(*a)->elements->next->data > (*a)->elements->next->next->data)
			*a = rra(*a, TRUE);
	}
}
