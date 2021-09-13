/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:43:29 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/13 17:12:35 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	very_small_sort(t_stack **a)
{
	t_element	*elements[3];

	elements[0] = (*a)->elements;
	elements[1] = elements[0]->next;
	elements[2] = elements[1]->next;
	if (elements[0]->data < elements[1]->data && elements[1]->data > \
	elements[2]->data && elements[2]->data > elements[0]->data)
	{
		*a = sa(*a, TRUE);
		*a = ra(*a, TRUE);
	}
	else if (elements[0]->data > elements[1]->data && elements[1]->data < \
	elements[2]->data && elements[2]->data > elements[0]->data)
		*a = sa(*a, TRUE);
	else if (elements[0]->data < elements[1]->data && elements[1]->data > \
	elements[2]->data && elements[2]->data < elements[0]->data)
		*a = rra(*a, TRUE);
	else if (elements[0]->data > elements[1]->data && elements[1]->data < \
	elements[2]->data && elements[0]->data > elements[2]->data)
		*a = ra(*a, TRUE);
	else
	{
		*a = ra(*a, TRUE);
		*a = sa(*a, TRUE);
	}
}
