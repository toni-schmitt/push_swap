/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:09:24 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/13 18:09:37 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort_ascending_case(t_stack **a, t_stack **b)
{
	t_element	*second;
	t_element	*third;
	t_element	*fourth;

	second = (*a)->elements->next;
	third = second->next;
	fourth = third->next;
	if (second->data > third->data && third->data > fourth->data \
		&& fourth->data > get_last_element(*a)->data)
	{
		if (fourth->data < (*a)->elements->data)
			*a = rra(*a, TRUE);
		*a = rra(*a, TRUE);
		pb(a, b);
		pb(a, b);
		very_small_sort(a);
		pa(a, b);
		pa(a, b);
	}
}

void	small_sort(t_stack **a, t_stack **b)
{
	small_sort_ascending_case(a, b);
	while (!is_sorted(*a))
	{
		while (!is_sorted(*a))
		{
			if ((*a)->elements->data > get_last_element(*a)->data)
				*a = ra(*a, TRUE);
			else if ((*a)->elements->data > (*a)->elements->next->data)
				*a = sa(*a, TRUE);
			else if ((*a)->elements->data < (*a)->elements->next->data)
				pb(a, b);
		}
		while ((*b)->elements)
			pa(a, b);
	}
}
