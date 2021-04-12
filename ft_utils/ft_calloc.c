/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:23:52 by avieira           #+#    #+#             */
/*   Updated: 2019/10/18 16:35:55 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int					*alloc;
	size_t				i;

	if (!(alloc = malloc(size * count)))
		return (NULL);
	if (!count || !size)
		return (malloc(1));
	i = 0;
	while (i < count)
		alloc[i++] = 0;
	return ((void *)alloc);
}
