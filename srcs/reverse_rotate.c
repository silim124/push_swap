/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:30 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:17 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	r_rotate_a(t_stack *a)
{
	t_data	x;

	if (a->top)
	{
		x = r_pop_stack(a);
		add_node(a, x);
	}
	return (write(1, "rra\n", 4));
}

int	r_rotate_b(t_stack *b)
{
	t_data	x;

	if (b->top)
	{
		x = r_pop_stack(b);
		add_node(b, x);
	}
	return (write(1, "rrb\n", 4));
}

int	r_rotate_together(t_stack *a, t_stack *b)
{
	t_data	x;

	if (a->top)
	{
		x = r_pop_stack(a);
		add_node(a, x);
	}
	if (b->top)
	{
		x = r_pop_stack(b);
		add_node(b, x);
	}
	return (write(1, "rrr\n", 4));
}
