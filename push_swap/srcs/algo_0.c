/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:17:08 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 11:30:25 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	trie_fin(t_stack *p)
{
	t_noeud	*last_no;

	last_no = get_last_noeud(p->a);
	if (p->b->index > p->a->index && p->b->index < p->a->next->index)
	{
		if (p->b->next && p->b->next->next \
		&& p->b->next->index < p->b->next->next->index)
			use_instruction(TRUE, p, 2, PA, SS);
		else
			use_instruction(TRUE, p, 2, PA, SA);
		return ;
	}
	if (p->b->index > last_no->index && p->b->index < p->a->index)
	{
		use_instruction(TRUE, p, 1, PA);
		return ;
	}
	else if (p->b->index > last_no->index)
		use_instruction(TRUE, p, 1, RA);
	else
		use_instruction(TRUE, p, 1, RRA);
	return (trie_fin(p));
}

static void	pre_trie(t_stack *p, int sezieme)
{
	trie_mediane_min(p, sezieme);
	trie_mediane_max(p, sezieme);
}

static void	trie_f(t_stack *p)
{
	while (p->b)
		trie_fin(p);
	faire_r_ou_rr(p, find_min(p->a)->pos, STACK_A);
}

void	trie_rapide(t_stack *p)
{
	pre_trie(p, p->len_total / 16);
	trie_f(p);
}
