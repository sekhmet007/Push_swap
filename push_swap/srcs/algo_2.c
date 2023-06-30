/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:17:41 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:40:35 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	trie_seizieme_max_botom(t_stack *p, int seizieme)
{
	while (p->b->index > seizieme * 8)
	{
		if (p->b->index >= seizieme * 9)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_noeud(p->b)->index < seizieme * 10)
		use_instruction(TRUE, p, 1, RRB);
	while (p->a->index && p->a->index < seizieme * 11)
		use_instruction(TRUE, p, 1, PB);
	while (get_last_noeud(p->b)->index > seizieme * 8)
	{
		if (get_last_noeud(p->b)->index \
		&& get_last_noeud(p->b)->index >= seizieme * 11)
			use_instruction(TRUE, p, 2, RRB, PA);
		else
			use_instruction(TRUE, p, 1, RRB);
	}
	while (p->a->index && p->a->index < seizieme * 13)
		use_instruction(TRUE, p, 1, PB);
}

static void	trie_seizieme_max_mid(t_stack *p, int seizieme)
{
	t_noeud	*last_ma;

	last_ma = get_last_noeud(p->a);
	while (p->a != last_ma)
	{
		if (p->a->index && p->a->index <= seizieme * 14)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->b->index >= seizieme * 13)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	if (p->a->index && p->a->index <= seizieme * 14)
	{
		use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= seizieme * 13)
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_noeud(p->b)->index > seizieme * 8)
		use_instruction(TRUE, p, 1, RRB);
}

static void	trie_seizieme_max_top(t_stack *p, int seizieme)
{
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= seizieme * 15)
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_noeud(p->b)->index > seizieme * 8)
		use_instruction(TRUE, p, 1, RRB);
}

void	trie_mediane_max(t_stack *p, int seizieme)
{
	t_noeud	*last_ma;

	last_ma = get_last_noeud(p->a);
	while (p->a != last_ma)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		else if (p->a->index <= seizieme * 12)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->b->index >= seizieme * 10)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	if (p->a->index && p->a->index <= seizieme * 12)
	{
		use_instruction(TRUE, p, 1, PB);
		if (p->b->index <= seizieme * 10)
			use_instruction(TRUE, p, 1, RB);
	}
	trie_seizieme_max_botom(p, seizieme);
	trie_seizieme_max_mid(p, seizieme);
	trie_seizieme_max_top(p, seizieme);
}
