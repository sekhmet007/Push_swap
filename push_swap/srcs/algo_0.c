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

/*petitQuick
trie_fin(t_stack *p): cette fonction sert à finaliser le tri en déplaçant 
les éléments de la pile b vers la pile a tout en maintenant la pile a triée.

pre_trie(t_stack *p, int sezieme): cette fonction prépare le tri en effectuant 
des opérations préliminaires de tri sur la pile a. 
Cela semble se faire par le biais des fonctions trie_mediane_min et 
trie_mediane_max, qui ne sont pas définies dans le code fourni, 
mais qui, comme leur nom l'indique, semblent manipuler des valeurs 
médianes pour faciliter le tri.

trie_f(t_stack *p): cette fonction finalise le tri en appelant la 
fonction trie_fin jusqu'à ce que la pile b soit vide, 
puis en faisant pivoter la pile a jusqu'à ce que le plus 
petit élément soit au sommet.

trie_rapide(t_stack *p): c'est la fonction principale de tri qui organise 
le processus de tri en trois étapes : pré-tri, tri final,
et ajustement final.
*/
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
