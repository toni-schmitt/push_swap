/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:23:45 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/15 18:18:00 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

/* PARSE_INPUT */
void		parse_input(t_stack **a, int argc, char *argv[]);

/* SORTING */
void		big_sort(t_stack **a, t_stack **b);
void		small_sort(t_stack **a, t_stack **b);
void		very_small_sort(t_stack **a);
/* INDEXING */
int			*quick_sort(t_stack *stack);
t_stack		*index_stack(t_stack *stack);

#endif