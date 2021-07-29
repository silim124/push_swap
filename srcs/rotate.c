/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:32 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:18 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_a(t_stack *a)
{
	t_data	x;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		r_add_node(a, x);
	}
	return (write(1, "ra\n", 3));
}

int	rotate_b(t_stack *b)
{
	t_data	x;

	if (b->bottom->up)
	{
		x = pop_stack(b);
		r_add_node(b, x);
	}
	return (write(1, "rb\n", 3));
}

int	rotate_together(t_stack *a, t_stack *b)
{
	t_data	x;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		r_add_node(a, x);
	}
	if (b->bottom->up)
	{
		x = pop_stack(b);
		r_add_node(b, x);
	}
	return (write(1, "rr\n", 3));
}
