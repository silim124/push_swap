/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:24 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:15 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ascending(t_stack a)
{
	while (--a.len)
	{
		if (a.top->data.value > a.top->down->data.value)
			return (1);
		a.top = a.top->down;
	}
	return (0);
}

int	save_orders(t_stack *stack, int num)
{
	int		i;
	t_node	*num_ptr;
	t_node	*iter_ptr;

	i = -1;
	while (++i < num)
	{
		num_ptr = stack->bottom;
		while (num_ptr->data.order)
			num_ptr = num_ptr->up;
		iter_ptr = num_ptr->up;
		while (iter_ptr)
		{
			if (num_ptr->data.value < iter_ptr->data.value
				&& !iter_ptr->data.order)
				num_ptr = iter_ptr;
			else if (num_ptr->data.value == iter_ptr->data.value)
				return (write(1, "Error\n", 6));
			iter_ptr = iter_ptr->up;
		}
		num_ptr->data.order = stack->len - i;
	}
	if (!check_ascending(*stack))
		return (1);
	return (0);
}

void	rewind_stack(t_stack *a, t_stack *b, t_operation op)
{
	int	common;
	int	diff;

	common = -1;
	while (++common < op.ra && common < op.rb)
	{
		r_rotate_together(a, b);
	}
	diff = ft_abs(op.ra - op.rb);
	while (diff-- > 0)
	{
		if (op.ra > op.rb)
			r_rotate_a(a);
		else if (op.ra < op.rb)
			r_rotate_b(b);
	}
}

int	ft_max_order(t_stack *s, int n)
{
	t_node	*node;
	int		max_order;

	node = s->top;
	max_order = node->data.order;
	while (n-- && node)
	{
		if (node->data.order >= max_order)
			max_order = node->data.order;
		node = node->down;
	}
	return (max_order);
}
