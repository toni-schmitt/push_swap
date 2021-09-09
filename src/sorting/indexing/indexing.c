/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:41:01 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/09 09:28:41 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*index_stack(t_stack *stack)
{
	int			*sorted_arr;
	int			j;
	t_element	*copy;

	copy = stack->elements;
	sorted_arr = quickSort(stack);
	while (copy)
	{
		j = 0;
		while (j <= stack->size)
		{
			if (copy->data == sorted_arr[j])
			{
				copy->index = j;
				break ;
			}
			j++;
		}
		copy = copy->next;
	}
	free(sorted_arr);
	return (stack);
}
