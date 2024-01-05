/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:54:59 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 16:21:00 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	smallest(t_pile *a)
{
	int	min;

	if (a)
	{
		min = (a)->value;
		while ((a)->next)
		{
			if (min > (a)->next->value)
				min = (a)->next->value;
			(a) = (a)->next;
		}
	}
	else
		min = INT_MIN;
	return (min);
}

int	index_pile(t_pile *a, int n)
{
	int	i;

	i = 0;
	if (a)
	{
		while (n != a->value)
		{
			i++;
			(a) = (a)->next;
		}
	}
	return (i);
}

int	bigest(t_pile *a)
{
	int	max;

	if (a)
	{
		max = (a)->value;
		while ((a)->next)
		{
			if (max < (a)->next->value)
				max = (a)->next->value;
			(a) = (a)->next;
		}
	}
	else
		max = INT_MAX;
	return (max);
}

int	last_elem(t_pile *a)
{
	if (a)
	{
		while (a->next)
			a = a->next;
		return (a->value);
	}
	else
		return (INT_MIN);
}

int	is_in_pile(t_pile *a, int min, int max)
{
	if (a)
	{
		while (a)
		{
			if (a->value <= max && a->value > min)
				return (1);
			a = a->next;
		}	
	}
	return (0);
}
