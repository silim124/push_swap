/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:22 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 19:11:07 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_sort_init(t_stack *s1, t_stack *s2, int start, int end)
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
			rotate_a(s1);
		else
		{
			push_b(s1, s2);
			if (s2->top->data.order <= pivot.small)
				rotate_b(s2);
		}
	}
	ft_sort_a(s1, s2, pivot.big, end);
	ft_sort_b(s1, s2, pivot.small, pivot.big);
	return (ft_sort_b(s1, s2, start, pivot.small));
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (!argv[1])
		return (0);
	init_stack(&a, &b);
	if (!add_nodes(&a, argc, argv) && !save_orders(&a, a.len))
		ft_sort_init(&a, &b, 0, a.len);
	clear_stack(&a, &b);
	return (0);
}
