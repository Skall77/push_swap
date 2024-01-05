/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:35:38 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 19:12:47 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sort(t_pile **a, t_pile **b)
{
	if (pile_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (pile_size(*a) == 3)
		sort_three(a);
	else if (pile_size(*a) <= 5)
		sort_five(a, b);
	else if (pile_size(*a) <= 250)
	{
		sort_hundreds(a, b);
		push_b(a, b);
		efficient_push(a);
	}
	else
	{
		radix_sort(a, b);
	}
}

void	sort_three(t_pile **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->value < third_value(*a)
		&& (*a)->next->value < third_value(*a))
		sa(a);
	else if ((*a)->value > (*a)->next->value && (*a)->value > third_value(*a)
		&& (*a)->next->value > third_value(*a))
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->value > (*a)->next->value && (*a)->value > third_value(*a)
		&& (*a)->next->value < third_value(*a))
		ra(a);
	else if ((*a)->value < (*a)->next->value && (*a)->value < third_value(*a)
		&& (*a)->next->value > third_value(*a))
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->value < (*a)->next->value && (*a)->value > third_value(*a)
		&& (*a)->next->value > third_value(*a))
		rra(a);
}	

void	sort_five(t_pile **a, t_pile **b)
{
	int	i;

	i = pile_size(*a);
	while (pile_size(*a) != 3)
	{
		if (index_pile(*a, smallest(*a)) < 3)
			while ((*a)->value != smallest(*a))
				ra(a);
		else
			while ((*a)->value != smallest(*a))
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (pile_size(*a) != i)
		pa(a, b);
}

void	sort_hundreds(t_pile **a, t_pile **b)
{
	int	median;

	median = find_median(*a);
	if (median == INT_MIN)
	{
		clear_pile(a, b);
		exit(-1);
	}
	while (is_in_pile(*a, INT_MIN, median))
	{
		if ((*a)->value <= median)
			pb(a, b);
		else if (last_elem(*a) <= median)
			rra(a);
		else
			ra(a);
	}
	if (pile_size(*a) <= 1)
		return ;
	sort_hundreds(a, b);
}

void	radix_sort(t_pile **a, t_pile **b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = pile_size(*a);
	while (!sorted(*a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (pile_size(*b) != 0)
		{
			pa(a, b);
		}
		i++;
	}
}
