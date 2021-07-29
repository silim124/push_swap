/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:17 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 18:17:11 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	put_error(void)
{
	return (write(1, "Error\n", 6));
}

int	free_buffer(char **buf, int str_idx)
{
	int	i;

	i = str_idx - 1;
	while (buf[++i])
		free(buf[i]);
	free(buf);
	return (put_error());
}

void	clear_stack(t_stack *stack1, t_stack *stack2)
{
	while (stack1 && stack1->len)
		pop_stack(stack1);
	while (stack2 && stack2->len)
		pop_stack(stack2);
}
