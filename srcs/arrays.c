/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:27:48 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 19:13:31 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sort_array(int *array, int len)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

int	find_median(t_pile *a)
{
	int	i;
	int	*array;
	int	len;
	int	median;

	i = 0;
	len = pile_size(a);
	array = malloc(sizeof(int) * len);
	if (!array)
		return (INT_MIN);
	while (i < len)
	{
		array[i] = a->value;
		a = a->next;
		i++;
	}
	sort_array(array, len);
	median = array[len / 3];
	free(array);
	return (median);
}

int	most_efficient(t_pile *a)
{
	int	max;
	int	min;
	int	ret_max;
	int	ret_min;

	ret_max = 2;
	ret_min = 1;
	if (index_pile(a, bigest(a)) < (pile_size(a) / 2))
		max = index_pile(a, bigest(a));
	else
	{
		max = (pile_size(a)) - index_pile(a, bigest(a));
		ret_max = -2;
	}
	if (index_pile(a, smallest(a)) < (pile_size(a) / 2))
		min = index_pile(a, smallest(a));
	else
	{
		min = (pile_size(a)) - index_pile(a, smallest(a));
		ret_min = -1;
	}
	if (max <= min)
		return (ret_max);
	else
		return (ret_min);
}
