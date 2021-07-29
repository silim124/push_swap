/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:44:07 by silim             #+#    #+#             */
/*   Updated: 2021/07/29 17:30:25 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int	value;
	int	order;
}		t_data;

typedef struct s_node
{
	t_data			data;
	struct s_node	*down;
	struct s_node	*up;
}					t_node;

typedef struct s_pivot
{
	int	big;
	int	small;
}		t_pivot;

typedef struct s_operation
{
	int	ra;
	int	rb;
}		t_operation;

typedef struct s_stack
{
	int		len;
	t_node	*bottom;
	t_node	*top;
}			t_stack;

/*	clear	*/
int		put_error(void);

int		free_buffer(char **buf, int str_idx);

void	clear_stack(t_stack *stack1, t_stack *stack2);

/*	reverse	rotate	*/
int		r_rotate_together(t_stack *a, t_stack	*b);

int		r_rotate_b(t_stack *b);

int		r_rotate_a(t_stack *a);

/*	rotate	*/
int		rotate_together(t_stack *a, t_stack *b);

int		rotate_b(t_stack *b);

int		rotate_a(t_stack *a);

/*	push	swap	*/
int		push_b(t_stack *a, t_stack *b);

int		push_a(t_stack *a, t_stack *b);

int		swap_together(t_stack *a, t_stack *b);

int		swap_b(t_stack *b);

int		swap_a(t_stack *a);

/*	add	pop	*/
t_data	pop_stack(t_stack *s);

t_data	r_pop_stack(t_stack *s);

void	r_add_node(t_stack *stack, t_data data);

void	add_node(t_stack *stack, t_data data);

int		add_nodes(t_stack *a, int argc, char **argv);

/*	init	stack	*/
void	init_stack(t_stack *a, t_stack *b);

t_node	*init_node(t_data data);

void	init_var(t_pivot *pivot, t_operation *op, int small, int big);

/*	sort	stack	*/
int		ft_sort_a(t_stack *s1, t_stack	*s2, int tart, int end);

int		sort_small_a(t_stack *s, int s_len);

int		ft_sort_b(t_stack *s1, t_stack *s2, int start, int end);

int		sort_small_b(t_stack *s1, t_stack *s2, int s_len);

int		sort_three(t_stack *s, int max);

/*	order	stack	*/
int		save_orders(t_stack *stack, int num);

int		check_ascending(t_stack a);

void	rewind_stack(t_stack *a, t_stack *b, t_operation rewind);

int		ft_max_order(t_stack *s, int n);

#endif
