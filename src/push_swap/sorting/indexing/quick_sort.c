/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toni <toni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:52:14 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/14 12:56:03 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Stolen from: https://www.geeksforgeeks.org/quick-sort/ */

// A utility function to swap two elements
static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
static void	sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		sort(arr, low, pi - 1);
		sort(arr, pi + 1, high);
	}
}

int	*quick_sort(t_stack *stack)
{
	int			*arr;
	int			i;
	t_element	*copy;

	copy = stack->elements;
	arr = malloc((stack->size) * sizeof(*arr));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		arr[i] = copy->data;
		copy = copy->next;
		i++;
	}
	sort(arr, 0, stack->size - 1);
	return (arr);
}
