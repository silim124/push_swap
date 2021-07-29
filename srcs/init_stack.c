/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:20 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:13 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_stack *a, t_stack *b)
{
	a->len = 0;
	a->top = NULL;
	a->bottom = NULL;
	b->len = 0;
	b->top = NULL;
	b->bottom = NULL;
}

t_node	*init_node(t_data data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->up = NULL;
	node->data.value = data.value;
	node->data.order = data.order;
	node->down = NULL;
	return (node);
}

void	init_var(t_pivot *pivot, t_operation *op, int small, int big)
{
	pivot->big = small + 2 * (big - small) / 3;
	pivot->small = small + (big - small) / 3;
	op->ra = 0;
	op->rb = 0;
}
