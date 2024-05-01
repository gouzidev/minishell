/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:15 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/27 22:20:48 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	gc_push(t_gc **gc, void *data)
{
	t_gc	*new;

	if (data == NULL)
	{
		gc_clear(gc);
		perror("malloc\n");
		exit(1);
	}
	new = malloc(sizeof(t_gc));
	if (new == 0)
	{
		gc_clear(gc);
		perror("malloc\n");
		exit(1);
	}
	new->data = data;
	new->next = *gc;
	*gc = new;
}

void	*gc_malloc(t_gc **gc, size_t size)
{
	t_gc	*new;
	void	*ptr;

	ptr = malloc(size);
	if (ptr == 0)
	{
		gc_clear(gc);
		perror("malloc\n");
		exit(1);
	}
	new = malloc(sizeof(t_gc));
	if (new == 0)
	{
		gc_clear(gc);
		perror("malloc\n");
		exit(1);
	}
	new->data = ptr;
	new->next = *gc;
	*gc = new;
	return (ptr);
}

t_gc	*gc_init(void)
{
	return (NULL);
}

void	gc_clear(t_gc **gc)
{
	t_gc	*curr;
	t_gc	*temp;

	curr = *gc;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp->data);
		free(temp);
	}
}
