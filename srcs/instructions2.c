/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:00:20 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 17:53:58 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ra_no_print(t_pile **a)
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
}

void	rb_no_print(t_pile **b)
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
}

void	rr(t_pile **a, t_pile **b)
{
	ra_no_print(a);
	rb_no_print(b);
	ft_printf("rr\n");
}

void	rra_no_print(t_pile **a)
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
}

void	rrb_no_print(t_pile **b)
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
}
