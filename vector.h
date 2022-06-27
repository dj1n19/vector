/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:14:32 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/24 19:14:36 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include <stdio.h>
# include <dlfcn.h>

typedef struct s_vector
{
	void	**ptr;
	size_t	size;
	size_t	max_size;
}	t_vector;

vector	*v_resize(vector *v);
void	v_destroy(vector *v);
void	v_puts(vector *v);
vector	*v_new(size_t size);
vector	*v_add(vector *v, void *p);
vector	*v_remove(vector *v, void *p);
vector	*v_clear(vector *v);

#endif
