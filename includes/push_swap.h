/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:20:18 by avieira           #+#    #+#             */
/*   Updated: 2021/10/14 15:44:08 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef enum e_opes
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_opes;

typedef struct s_stacks
{
	int			*a;
	int			*b;
	int			*len_a;
	int			*len_b;
}				t_stacks;

typedef struct s_input
{
	t_stacks	stacks;
	t_list		*opes;
}				t_input;

typedef struct s_chunk
{
	int			size;
	void		(*rotate)(t_stacks *, char, t_input *);
	int			min;
	int			max;
	int			min_value;
	int			max_value;
}				t_chunk;

void			error(t_input *input);
void			alloc_input(t_input *input, int ac);
void			free_input(t_input *input);
int				ft_atoi_of(const char *nptr, t_input *input);
void			get_stack(int ac, char **av, t_input *input);
void			get_opes(t_input *input);
void			exec_opes(t_input *input);
void			check_stacks(int *a, int *len_a, int *len_b);
void			swap_a(t_stacks *stacks, char sorting, t_input *input);
void			swap_b(t_stacks *stacks, char sorting, t_input *input);
void			swap_double(t_stacks *stacks, char sorting, t_input *input);
void			push_a(t_stacks *stacks, char sorting, t_input *input);
void			push_b(t_stacks *stacks, char sorting, t_input *input);
void			rotate_a(t_stacks *stacks, char sorting, t_input *input);
void			rotate_b(t_stacks *stacks, char sorting, t_input *input);
void			rotate_double(t_stacks *stacks, char sorting, t_input *input);
void			reverse_rotate_a(t_stacks *stacks, char sort, t_input *input);
void			reverse_rotate_b(t_stacks *stacks, char sort, t_input *inpt);
void			reverse_rotate_double(t_stacks *stck, char sort, t_input *inpt);
void			swap(int *a, int *len_a);
void			push(int *a, int *b, int *len_a, int *len_b);
void			rotate(int *a, int *len_a);
void			reverse_rotate(int *a, int *len_a);
void			reverse_array_index(int *a, int start, int end);
void			display_stacks(int *a, int *b, int *len_a, int *len_b);
void			transform_stack(t_input*input);
void			sort_stack(t_input *input);
void			find_nearer_of_chunk(t_stacks *s, int b, int t, t_chunk *chnk);
void			add_ope(t_opes *ope, t_input *input);
void			shift_b_before_push(t_stacks *stacks, t_input *input);
void			transform_order(int *order, int len);
int				is_sort(int *stack, int len);
void			sort_little(t_input *input, t_stacks *stacks);
void			del_ope_one(t_list **opes, t_list *to_del);

#endif
