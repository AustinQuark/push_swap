/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:34:42 by avieira           #+#    #+#             */
/*   Updated: 2021/10/14 15:42:14 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_find(int find[2], t_stacks *stacks)
{
	int		i;
	int		min_delta[2];
	int		delta;

	min_delta[0] = - (*stacks->len_b + *stacks->len_a);
	min_delta[1] = (*stacks->len_b + *stacks->len_a);
	i = -1;
	while (++i < *stacks->len_b)
	{
		delta = stacks->b[i] - *stacks->a;
		if (delta < 0 && delta > min_delta[0])
		{
			find[0] = i;
			min_delta[0] = delta;
		}
		else if (delta > 0 && delta < min_delta[1])
		{
			find[1] = i + 1;
			min_delta[1] = delta;
		}
	}
}

void	rearange_b(t_stacks *stacks, t_input *input)
{
	void	(*rotate)(t_stacks *, char, t_input *);
	int		find[2];
	int		found;

	find[0] = -1;
	find[1] = -1;
	get_find(find, stacks);
	found = find[0];
	if (found == -1)
		found = find[1];
	rotate = &rotate_b;
	if (found > (*stacks->len_b) / 2)
	{
		found = *stacks->len_b - found;
		rotate = &reverse_rotate_b;
	}
	while (found-- > 0)
		rotate(stacks, 1, input);
}

void	sort_chunk(t_input *input, int bot, int top)
{
	t_chunk	chunk;
	int		i;

	chunk.rotate = NULL;
	find_nearer_of_chunk(&input->stacks, bot, top, &chunk);
	chunk.size = 1 + chunk.max - chunk.min;
	chunk.min_value = input->stacks.a[chunk.min];
	chunk.max_value = input->stacks.a[chunk.max];
	while (*input->stacks.a != chunk.max_value
		&& *input->stacks.a != chunk.min_value)
		chunk.rotate(&input->stacks, 1, input);
	i = -1;
	while (++i < chunk.size)
	{
		if (*input->stacks.a >= bot && *input->stacks.a <= top
			&& *input->stacks.len_a)
		{
			if (*input->stacks.len_b)
				rearange_b(&input->stacks, input);
			push_b(&input->stacks, 1, input);
			i--;
		}
		else
			chunk.rotate(&input->stacks, 1, input);
	}
}

void	sort_big(t_input *input)
{
	int		n_chunk;
	int		i;
	double	size_chunk;

	size_chunk = -0.00004 * (*input->stacks.len_a * *input->stacks.len_a)
		+ 0.08 * *input->stacks.len_a + 9.4;
	n_chunk = *input->stacks.len_a / (int)size_chunk;
	if (*input->stacks.len_a % (int)size_chunk)
		n_chunk++;
	i = -1;
	while (++i < n_chunk)
		sort_chunk(input, i * (int)size_chunk, ((i + 1) * (int)size_chunk - 1));
	shift_b_before_push(&input->stacks, input);
	while (*input->stacks.len_b)
		push_a(&input->stacks, 1, input);
}

void	sort_stack(t_input *input)
{
	if (is_sort(input->stacks.a, *input->stacks.len_a))
		return ;
	if (*input->stacks.len_a < 6)
		sort_little(input, &input->stacks);
	else
		sort_big(input);
}
