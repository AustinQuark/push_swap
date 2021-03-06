/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:17:35 by avieira           #+#    #+#             */
/*   Updated: 2021/10/14 15:10:35 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_ope(t_opes *ope, t_input *input)
{
	t_list	*new_ope;

	new_ope = ft_lstnew(ope);
	if (!new_ope)
		error(input);
	ft_lstadd_back(&input->opes, new_ope);
}

int	is_sort(int *stack, int len)
{
	int		temp;
	int		i;

	i = 0;
	temp = stack[i];
	while (++i < len)
	{
		if (stack[i] < temp)
			return (0);
		temp = stack[i];
	}
	return (1);
}

void	find_nearer_of_chunk(t_stacks *stack, int bot, int top, t_chunk *chunk)
{
	int		i;

	i = 0;
	chunk->min = -1;
	chunk->max = -1;
	while (i < *stack->len_a && chunk->min == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			chunk->min = i;
		i++;
	}
	i = *stack->len_a - 1;
	while (i > -1 && chunk->max == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			chunk->max = i;
		i--;
	}
	if (chunk->min < (*stack->len_a - chunk->max))
		chunk->rotate = &rotate_a;
	else
		chunk->rotate = &reverse_rotate_a;
}

void	shift_b_before_push(t_stacks *stacks, t_input *input)
{
	int		i;
	void	(*rotate)(t_stacks *, char, t_input *);

	i = 0;
	while (stacks->b[i])
		i++;
	rotate = &rotate_b;
	if (i > (*stacks->len_b) / 2)
	{
		i = *stacks->len_b - i - 1;
		rotate = &reverse_rotate_b;
	}
	else
		i++;
	while (i--)
		rotate(stacks, 1, input);
}
