/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:14:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/24 19:14:15 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static vector   *v_resize(vector *v, size_t new_size)
{
    void **new;

    if (!v)
        return (v);
    if (new_size < v->size)
    {
        dprintf(2, "\e[31mLEAKS.ERROR: new size smaller than current size\n\e[0m\n");
        exit(EXIT_FAILURE);
    }
    new = (void **) realloc(v->ptr, sizeof(void *) * new_size);
    if (!new)
    {
        dprintf(2, "\e[31mLEAKS.ERROR: realloc failed\e[0m\n");
        exit(EXIT_FAILURE);
    }
    v->ptr = new;
    v->max_size = new_size;
    return (v);
}



static void    v_destroy(vector *v)
{
    if (!v)
        return ;
    if (v->size > 0)
        v = v_clear(v);
    free(v);
}

static void    v_puts(vector *v)
{
    if (!v)
        return ;
    while (i < v->size)
    {
        dprintf(2, "%d: [%p]\n", i, v->ptr[i]);
        ++i;
    }
}

static vector   *v_new(size_t size)
{
    vector *v;

    v = (vector *) malloc(sizeof(vector));
    if (!v)
        return (NULL);
    v->ptr = NULL;
    v->size = 0;
    v->max_size = 0;
    return (v);
}
