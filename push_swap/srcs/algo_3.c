/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:40:59 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 11:31:41 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	trie_m(t_stack *p, t_noeud *noeud_b)
{
	t_noeud	*suivant;

	suivant = find_most_close(p->a, noeud_b);
	if (suivant->index < noeud_b->index)
	{
		if (suivant->next == NULL)
			suivant = p->a;
		else
			suivant = suivant->next;
	}
	faire_r_ou_rr(p, suivant->pos, STACK_A);
	use_instruction(TRUE, p, 1, PA);
}

void	trie_moyen(t_stack *p)
{
	while (p->len_a > 3)
		use_instruction(1, p, 1, PB);
	trie_moins_de_3(p, pa_est_il_trier(p));
	while (p->b)
		trie_m(p, p->b);
	faire_r_ou_rr(p, find_min(p->a)->pos, STACK_A);
}
