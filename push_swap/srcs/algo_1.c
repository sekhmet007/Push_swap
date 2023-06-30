/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:26:38 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:29:10 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	trie_quart_min(t_stack *p, int quartile)
{
	if (!p->b)
		return ;
	while (p->b->index >= quartile)
	{
		if (p->b->index > quartile + (quartile / 2))
		{
			use_instruction(TRUE, p, 1, PA);
		}
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index <= quartile)
	{
		if (p->b->index < quartile - (quartile / 2))
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
}

static void	trie_seizieme_mid_extrem(t_stack *p, int huitieme)
{
	while (p->a->index <= huitieme)
	{
		if (!p->a->index)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= (huitieme / 2))
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index <= huitieme)
		use_instruction(TRUE, p, 1, RB);
	while (p->a->index <= huitieme * 4)
	{
		if (!p->a->index)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= (huitieme * 4) - (huitieme / 2))
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_noeud(p->b)->index > huitieme)
		use_instruction(TRUE, p, 1, RRB);
}

static void	trie_seizieme_min_mid(t_stack *p, int siezieme)
{
	while (p->b->index >= (siezieme * 4))
	{
		if (p->b->index >= (siezieme * 5))
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index <= (siezieme * 4))
	{
		if (p->b->index <= (siezieme * 3))
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->a->index <= (siezieme * 4))
		use_instruction(TRUE, p, 2, PB, RB);
	while (p->a->index > siezieme * 2)
		use_instruction(TRUE, p, 1, PB);
}

void	trie_mediane_min(t_stack *p, int seizieme)
{
	int	mediane;
	int	huitieme;

	huitieme = seizieme * 2;
	mediane = seizieme * 8;
	while (p->len_b + 1 <= mediane)
	{
		if (p->a->index == 0)
			use_instruction(TRUE, p, 1, RA);
		if (p->a->index <= mediane)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->len_b > 1 && p->b->index <= mediane / 2)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	trie_quart_min(p, seizieme * 4);
	trie_seizieme_min_mid(p, seizieme);
	trie_seizieme_mid_extrem(p, huitieme);
}
