/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:27:11 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/07 15:07:56 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sa(t_pile **a)
{
	t_pile	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
	}
	ft_printf("sa\n");
}

void	sb(t_pile **b)
{
	t_pile	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		*b = tmp;
	}
	ft_printf("sb\n");
}

void	ss(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		*b = tmp;
	}
	ft_printf("ss\n");
}

void	pa(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	ft_printf("pa\n");
}

void	pb(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	ft_printf("pb\n");
}
