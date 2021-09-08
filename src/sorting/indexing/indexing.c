/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:41:01 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/08 16:54:53 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*index_stack(t_stack *stack)
{
	int		*sorted_arr;
	int		j;
	int		stack_size;
	t_stack	*copy;

	copy = stack;
	sorted_arr = quickSort(copy);
	stack_size = get_stack_size(copy);
	while (copy)
	{
		j = 0;
		while (j <= stack_size)
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
