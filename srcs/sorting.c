/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:14:42 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 17:42:27 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	efficient_push(t_pile **a)
{
	if (index_pile(*a, smallest(*a)) < (pile_size(*a) / 2))
	{
		while ((*a)->value != smallest(*a))
			ra(a);
	}
	else
	{
		while ((*a)->value != smallest(*a))
			rra(a);
	}
}

void	push_b(t_pile **a, t_pile **b)
{
	while (pile_size(*b))
	{
		if (most_efficient(*b) == -2)
		{
			while ((*b)->value != bigest(*b))
				rrb(b);
			pa(a, b);
		}
		else if (most_efficient(*b) == -1)
		{
			rrb_when_small(b);
			pa_and_ra(a, b);
		}
		else if (most_efficient(*b) == 1)
		{
			rb_when_small(b);
			pa_and_ra(a, b);
		}
		else if (most_efficient(*b) == 2)
		{
			while ((*b)->value != bigest(*b))
				rb(b);
			pa(a, b);
		}
	}
}

void	rb_when_small(t_pile **b)
{
	while ((*b)->value != smallest(*b))
		rb(b);
}

void	rrb_when_small(t_pile **b)
{
	while ((*b)->value != smallest(*b))
		rrb(b);
}

void	pa_and_ra(t_pile **a, t_pile **b)
{
	pa(a, b);
	ra(a);
}
