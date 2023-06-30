/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:02:40 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/28 10:02:52 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free

void	*free_lst_noeud(t_noeud **s)
{
	if (!s || !(*s))
		return (NULL);
	(*s)->index = 0;
	(*s)->pos = 0;
	(*s)->val = 0;
	(*s)->prev = NULL;
	free_lst_noeud(&(*s)->next);
	(*s)->next = NULL;
	free(*s);
	*s = NULL;
	return (NULL);
}

void	*free_struct_stack(t_stack **p)
{
	if (!p || !(*p))
		return (NULL);
	free_lst_noeud(&((*p)->a));
	(*p)->a = NULL;
	free_lst_noeud(&((*p)->b));
	(*p)->b = NULL;
	(*p)->len_a = 0;
	(*p)->len_b = 0;
	(*p)->len_total = 0;
	free(*p);
	*p = NULL;
	return (NULL);
}
