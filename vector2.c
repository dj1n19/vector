/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:25:43 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/24 19:25:45 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

vector	*v_add(vector *v, void *p)
{
	if (!v || !p)
		return (v);
	if (v->size >= v->max_size)
		v = v_resize(v, v->max_size + 1);
	v->ptr[v->size] = p;
	v->size++;
	return (v);
}

vector	*v_remove(vector *v, void *p)
{
	int	i;

	i = 0;
	if (!v || !p)
		return (v);
	while (i < v->size && v->ptr[i])
		++i;
	while (i + 1 < v->size)
	{
		v->ptr[i] = v->ptr[i + 1];
		++i;
	}
	v->size--;
	return (v);
}

vector	*v_clear(vector *v)
{
	int	i;

	i = 0;
	while (i < v->size)
	{
		free(v->ptr[i]);
		++i;
	}
	v->size = 0;
	return (v);
}
