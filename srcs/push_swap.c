/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:27 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:16 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_a(t_stack *a)
{
	t_data	x;
	t_data	y;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		y = pop_stack(a);
		add_node(a, x);
		add_node(a, y);
	}
	write(1, "sa\n", 3);
	return (1);
}

int	swap_b(t_stack *b)
{
	t_data	x;
	t_data	y;

	if (b->bottom->up)
	{
		x = pop_stack(b);
		y = pop_stack(b);
		add_node(b, x);
		add_node(b, y);
	}
	write(1, "sb\n", 3);
	return (1);
}

int	swap_together(t_stack *a, t_stack *b)
{
	t_data	x;
	t_data	y;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		y = pop_stack(a);
		add_node(a, x);
		add_node(a, y);
	}
	if (b->bottom->up)
	{
		x = pop_stack(b);
		y = pop_stack(b);
		add_node(b, x);
		add_node(b, y);
	}
	write(1, "ss\n", 3);
	return (1);
}

int	push_a(t_stack *a, t_stack *b)
{
	t_data	x;

	if (b->bottom)
	{
		x = pop_stack(b);
		add_node(a, x);
	}
	return (write(1, "pa\n", 3));
}

int	push_b(t_stack *a, t_stack *b)
{
	t_data	x;

	if (a->bottom)
	{
		x = pop_stack(a);
		add_node(b, x);
	}
	return (write(1, "pb\n", 3));
}
