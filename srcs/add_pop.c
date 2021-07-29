/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:13 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:10 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node(t_stack *stack, t_data data)
{
	t_node	*new_node;

	new_node = init_node(data);
	new_node->down = stack->top;
	if (stack->top)
	{
		stack->top->up = new_node;
		stack->top = new_node;
	}
	else
	{
		stack->bottom = new_node;
		stack->top = new_node;
	}
	stack->len++;
}

void	r_add_node(t_stack *stack, t_data data)
{
	t_node	*new_node;

	new_node = init_node(data);
	new_node->up = stack->bottom;
	if (stack->bottom)
	{
		stack->bottom->down = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->bottom = new_node;
		stack->top = new_node;
	}
	stack->len++;
}

t_data	pop_stack(t_stack *s)
{
	t_data	temp_value;
	t_node	*temp;

	temp_value.value = s->top->data.value;
	temp_value.order = s->top->data.order;
	temp = s->top;
	s->top = s->top->down;
	free(temp);
	s->len -= 1;
	if (!s->len)
	{
		s->bottom = NULL;
		s->top = NULL;
	}
	else
		s->top->up = NULL;
	return (temp_value);
}

t_data	r_pop_stack(t_stack *s)
{
	t_data	temp_value;
	t_node	*temp;

	temp_value.value = s->bottom->data.value;
	temp_value.order = s->bottom->data.order;
	temp = s->bottom;
	s->bottom = s->bottom->up;
	free(temp);
	s->len -= 1;
	if (!s->len)
	{
		s->top = NULL;
		s->bottom = NULL;
	}
	else
		s->bottom->down = NULL;
	return (temp_value);
}

int	add_nodes(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	t_data	data;

	i = 0;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = -1;
		while (str[++j])
		{
			if (!ft_isnum(str[j]) || !ft_isint(str[j]))
				return (free_buffer(str, j));
			data.value = ft_atoi(str[j]);
			data.order = 0;
			r_add_node(a, data);
			free(str[j]);
		}
		free(str);
	}
	if (!a->len)
		return (put_error());
	return (0);
}
