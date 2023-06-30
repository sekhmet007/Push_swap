/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:05:20 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:25:21 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//fonction utile

t_noeud	*find_min(t_noeud *head)
{
	t_noeud	*index;
	t_noeud	*res;

	index = head;
	res = head;
	while (index)
	{
		if (index->index < res->index)
			res = index;
		if (res->index == 0)
			return (res);
		index = index->next;
	}
	return (res);
}

t_noeud	*find_max(t_noeud *head)
{
	t_noeud	*index;
	t_noeud	*res;

	index = head;
	res = head;
	while (index)
	{
		if (index->index > res->index)
			res = index;
		index = index->next;
	}
	return (res);
}
//trouve le noeud le plus proche

t_noeud	*find_most_close(t_noeud *head_a, t_noeud *noeud_b)
{
	t_noeud	*res;
	int		diff_index;
	int		buff;
	t_noeud	*index;

	index = head_a;
	diff_index = 0;
	while (index)
	{
		if (noeud_b->index > index->index)
			buff = noeud_b->index - index->index;
		else
			buff = index->index - noeud_b->index;
		if (!diff_index || buff < diff_index)
		{
			res = index;
			diff_index = buff;
		}
		index = index->next;
	}
	return (res);
}
//initialise les structures

int	init_struct(t_stack **pils, int argc, char **argv)
{
	t_noeud	*a;

	a = check_arg(0, argc, argv, NULL);
	if (a == NULL)
		return (1);
	(*pils) = creat_struct(a);
	if ((*pils) == NULL)
		return (1);
	return (0);
}
