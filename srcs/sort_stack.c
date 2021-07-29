/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:35 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:19 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_three(t_stack *s, int max)
{
	if (s->len == 3)
	{
		if (s->top->data.order == max)
			rotate_a(s);
		if (s->top->data.order > s->top->down->data.order)
			swap_a(s);
		else if (s->top->down->data.order == max)
			r_rotate_a(s);
	}
	else if (s->top->data.order == max || s->top->down->data.order == max)
	{
		if (s->top->data.order == max)
			swap_a(s);
		rotate_a(s);
		swap_a(s);
		r_rotate_a(s);
	}
	if (s->top->data.order > s->top->down->data.order)
		swap_a(s);
	return (1);
}

int	sort_small_a(t_stack *s, int s_len)
{
	if (s_len == 2 && s->top->data.order > s->top->down->data.order)
		return (swap_a(s));
	else if (s_len == 3 || s->len == 3)
		return (sort_three(s, ft_max_order(s, 3)));
	return (1);
}

int	ft_sort_a(t_stack *s1, t_stack *s2, int start, int end)
{
	t_operation	op;
	t_pivot		pivot;
	int			i;

	i = -1;
	if (end - start <= 3)
		return (sort_small_a(s1, end - start));
	init_var(&pivot, &op, start, end);
	while (++i < end - start)
	{
		if (s1->top->down && s1->top->data.order > pivot.big)
			rotate_a(s1), ++op.ra;
		else
		{
			push_b(s1, s2);
			if (s2->top->data.order > pivot.small)
				rotate_b(s2), ++op.rb;
		}
	}
	rewind_stack(s1, s2, op);
	ft_sort_a(s1, s2, pivot.big, end);
	ft_sort_b(s1, s2, pivot.small, pivot.big);
	return (ft_sort_b(s1, s2, start, pivot.small));
}

int	sort_small_b(t_stack *s1, t_stack *s2, int s_len)
{
	if (s_len == 1)
		return (push_a(s1, s2));
	else if (s_len == 2)
	{
		if (s2->top->data.order < s2->top->down->data.order)
			swap_b(s2);
		push_a(s1, s2), push_a(s1, s2);
	}
	else if (s_len == 3)
	{
		push_a(s1, s2), push_a(s1, s2), push_a(s1, s2);
		sort_three(s1, ft_max_order(s1, 3));
	}
	return (1);
}

int	ft_sort_b(t_stack *s1, t_stack *s2, int start, int end)
{
	t_operation	op;
	t_pivot		pivot;
	int			i;

	i = -1;
	if (end - start <= 3)
		return (sort_small_b(s1, s2, end - start));
	init_var(&pivot, &op, start, end);
	while (++i < end - start)
	{
		if (s2->top->down && s2->top->data.order <= pivot.small)
			rotate_b(s2), ++op.rb;
		else
		{
			push_a(s1, s2);
			if (s1->top->data.order <= pivot.big)
				rotate_a(s1), ++op.ra;
		}
	}
	ft_sort_a(s1, s2, pivot.big, end);
	rewind_stack(s1, s2, op);
	ft_sort_a(s1, s2, pivot.small, pivot.big);
	return (ft_sort_b(s1, s2, start, pivot.small));
}
