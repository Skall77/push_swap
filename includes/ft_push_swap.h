/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:05 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 19:14:38 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
	int				value;
	int				index;
	struct s_pile	*next;
}					t_pile;

t_pile		*ft_pilenew(int n);
void		ft_pileadd_front(t_pile **pile, t_pile *new);
long long	ft_atoil(const char *nptr);
t_pile		*init_pile(t_pile *s, t_pile *b, char **av, int argc);
int			not_int(char **av);
int			is_dup(char **av);
int			is_int(char **av);
int			third_value(t_pile *a);
int			good_arguments(char **av);
int			ft_strcmp(char *s1, char *s2);
void		sa(t_pile **a);
void		sb(t_pile **b);
void		ss(t_pile **a, t_pile **b);
void		pa(t_pile **a, t_pile **b);
void		pb(t_pile **a, t_pile **b);
void		ra(t_pile **a);
void		rb(t_pile **b);
void		rr(t_pile **a, t_pile **b);
void		rra(t_pile **a);
void		rrb(t_pile **b);
void		rrr(t_pile **a, t_pile **b);
void		sort_hundreds(t_pile **a, t_pile **b);
int			sorted(t_pile *a);
int			pile_size(t_pile *a);
void		sort_three(t_pile **a);
void		sort(t_pile **a, t_pile **b);
void		sort_five(t_pile **a, t_pile **b);
int			index_pile(t_pile *a, int n);
int			smallest(t_pile *a);
int			bigest(t_pile *a);
void		push_b(t_pile **a, t_pile **b);
int			last_elem(t_pile *a);
void		sort_array(int *array, int len);
int			find_median(t_pile *a);
int			most_efficient(t_pile *a);
void		print_pile(t_pile *a);
int			is_in_pile(t_pile *a, int min, int max);
void		efficient_push(t_pile **a);
void		rrb_when_small(t_pile **b);
void		pa_and_ra(t_pile **a, t_pile **b);
void		rb_when_small(t_pile **b);
void		ra_no_print(t_pile **a);
void		rb_no_print(t_pile **b);
void		rra_no_print(t_pile **a);
void		rrb_no_print(t_pile **b);
void		clear_pile(t_pile **a, t_pile **b);
t_pile		*get_min(t_pile **a);
void		init_index(t_pile **a);
void		radix_sort(t_pile **a, t_pile **b);
void		handle_error(void);

#endif