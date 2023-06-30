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

/*trie rapide:
trie_m(t_stack *p, t_noeud *noeud_b): Cette fonction trie un seul nœud dans 
la pile. Elle trouve le nœud le plus proche (suivant) du nœud donné (noeud_b) 
dans la pile a. Si l'index de suivant est inférieur à l'index de noeud_b, 
elle ajuste suivant pour pointer vers le nœud suivant dans la pile, 
ou vers le début de la pile si aucun nœud suivant n'existe. 
Ensuite, elle fait tourner la pile a pour mettre suivant au sommet, 
et finalement elle pousse noeud_b du sommet de la pile b au sommet de la pile a.

trie_moyen(t_stack *p): Cette fonction est le contrôleur principal pour le tri
de la pile p. D'abord, tant que la taille de la pile a est supérieure à 3, 
elle pousse le sommet de a dans b. Ensuite, elle trie les trois derniers 
éléments restant dans a (en supposant qu'ils sont déjà dans l'ordre). 
Ensuite, pour chaque nœud dans b, elle utilise trie_m pour le trier dans a. 
Finalement, elle fait tourner la pile a pour mettre son plus petit élément 
au sommet.
*/
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
