#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
    long long	data;
    struct s_node		*up;
    struct s_node		*down;
} t_node;

typedef struct	s_stack
{
    t_node		*top;
    t_node		*bottom;
} t_stack;

void free_node(t_node *node)
{
    if (node)
    {
        free(node);
        node = NULL;
    }
}

t_node  *init_node(long long data)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    new_node->data = data;
    new_node->up = NULL;
    new_node->down = NULL;
    return (new_node);
}

void    init_stack(t_stack *stack1, t_stack *stack2)
{
    stack1->top = NULL;
    stack1->bottom = NULL;
    stack2->top = NULL;
    stack2->bottom = NULL;
}

void    add_top(t_stack *stack, long long data)
{
    t_node  *new_node;

    new_node = init_node(data);
    new_node->down = stack->top;
    if (stack->top)
    {
        stack->top->up = new_node;
        stack->top = new_node;
    }
    else
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
}

void    add_bottom(t_stack *stack, long long data)
{
    t_node  *new_node;

    new_node = init_node(data);
    new_node->up = stack->bottom;
    if (stack->top)
    {
        stack->bottom->down = new_node;
        stack->bottom = new_node;
    }
    else
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
}

long long pop_top(t_stack *stack)
{
    long long   old_top_data;
    t_node      *old_top;

    old_top_data = stack->top->data;
    old_top = stack->top;
    stack->top = stack->top->down;
    free_node(old_top);
    if (!stack->bottom)
       stack->top = NULL;
    return (old_top_data);
}

long long pop_bottom(t_stack *stack)
{
    long long   old_bottom_data;
    t_node      *old_bottom;

    old_bottom_data = stack->bottom->data;
    old_bottom = stack->bottom;
    stack->bottom = stack->bottom->up;
    free_node(old_bottom);
    if (!stack->top)
        stack->bottom = NULL;
    return (old_bottom_data);
}

void    swap(t_stack *stack)
{
    long long num1;
    long long num2;

    if (stack->top)
    {
        num1 = pop_top(stack);
        num2 = pop_top(stack);
        add_top(stack, num1);
        add_top(stack, num2);
    }
}

void    swap_together(t_stack *stack1, t_stack *stack2)
{
    swap(stack1);
    swap(stack2);
}

void    push(t_stack *stack1, t_stack *stack2)
{
    long long   num;

    if (stack1->bottom)
    {
        num = pop_top(stack1);
        add_top(stack2, num);
    }
}

void    rotate(t_stack  *stack)
{
    long long num;

    if (stack->top)
    {
        num = pop_top(stack);
        add_bottom(stack, num);
    }
}

void    reverse_rotate(t_stack  *stack)
{
    long long num;

    if (stack->top)
    {
        num = pop_bottom(stack);
        add_top(stack, num);
    }
}

void    rotate_together(t_stack *stack1, t_stack *stack2)
{
    rotate(stack1);
    rotate(stack2);
}

void    reverse_rotate_together(t_stack *stack1, t_stack *stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
}

int main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;

    init_stack(&stack_a, &stack_b);

    int i;

    printf("Hello, World!\n");

    t_stack stack;
    init_stack(&stack);
    i = 0;
    printf("stack :  ");
    while (++i < 3)
    {
        add_top(&stack, i);
        printf("%lld  ", stack.top->data);
    }
    printf("\nadd nodes done!\n");
    printf("\ntop : %lld\n",stack.top->data);
    printf("\nbottom : %lld\n",stack.bottom->data);
    pop_top(&stack);
    printf("\ntop : %lld\n",stack.top->data);
    reverse_rotate(&stack);
    printf("\ntop : %lld\n",stack.top->data);
    return 0;
}
