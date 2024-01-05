/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:28:25 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/11 12:46:38 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	rrr(t_pile **a, t_pile **b)
{	
	rra_no_print(a);
	rrb_no_print(b);
	ft_printf("rrr\n");
}

void	ra(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*a && (*a)->next)
	{
		tmp = (*a);
		*a = (*a)->next;
		head = *a;
		tmp->next = NULL;
		while ((*a)->next)
		{
			*a = (*a)->next;
		}
		(*a)->next = tmp;
		*a = head;
	}
	ft_printf("ra\n");
}

void	rb(t_pile **b)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*b && (*b)->next)
	{
		tmp = (*b);
		*b = (*b)->next;
		head = *b;
		tmp->next = NULL;
		while ((*b)->next)
		{
			*b = (*b)->next;
		}
		(*b)->next = tmp;
		*b = head;
	}
	ft_printf("rb\n");
}

void	rra(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*a && (*a)->next)
	{
		head = (*a);
		while ((*a)->next->next)
		{
			*a = (*a)->next;
		}
		tmp = (*a)->next;
		(*a)->next = NULL;
		*a = head;
		tmp->next = *a;
		*a = tmp;
	}
	ft_printf("rra\n");
}

void	rrb(t_pile **b)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*b && (*b)->next)
	{
		head = (*b);
		while ((*b)->next->next)
		{
			*b = (*b)->next;
		}
		tmp = (*b)->next;
		(*b)->next = NULL;
		*b = head;
		tmp->next = *b;
		*b = tmp;
	}
	ft_printf("rrb\n");
}
