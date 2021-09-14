/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:43:29 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/14 20:40:36 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_data(t_stack **a, int *data)
{
	if ((*a)->elements)
		data[0] = (*a)->elements->data;
	if ((*a)->elements->next)
		data[1] = (*a)->elements->next->data;
	if ((*a)->elements->next->next)
		data[2] = (*a)->elements->next->next->data;
}

void	very_small_sort(t_stack **a)
{
	int	data[3];

	get_data(a, data);
	if (data[0] < data[1] && data[1] > data[2] && data[2] > data[0])
	{
		*a = sa(*a, TRUE);
		*a = ra(*a, TRUE);
	}
	else if (data[0] > data[1] && data[1] < data[2] && data[2] > data[0])
		*a = sa(*a, TRUE);
	else if (data[0] < data[1] && data[1] > data[2] && data[2] < data[0])
		*a = rra(*a, TRUE);
	else if (data[0] > data[1] && data[1] < data[2] && data[0] > data[2])
		*a = ra(*a, TRUE);
	else
	{
		*a = ra(*a, TRUE);
		*a = sa(*a, TRUE);
	}
}
