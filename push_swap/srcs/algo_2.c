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

/*trie_seizieme_max_botom(t_stack *p, int seizieme): Cette fonction s'occupe 
de la partie inférieure (ou "bottom") de la pile. Elle déplace les éléments 
de la pile b à a ou effectue une rotation de b basée sur une comparaison de 
l'index de chaque élément avec certains multiples du seizième fourni. 
Ensuite, elle effectue des rotations sur la pile b pour mettre en ordre 
les éléments.

trie_seizieme_max_mid(t_stack *p, int seizieme): Cette fonction gère le 
milieu de la pile. Elle déplace des éléments de a à b ou effectue 
des rotations sur a selon la comparaison de l'index de chaque 
élément avec certains multiples du seizième. Ensuite, 
elle fait des rotations inverses sur b pour mettre les éléments en ordre.

trie_seizieme_max_top(t_stack *p, int seizieme): Cette fonction gère la partie
supérieure (ou "top") de la pile. Elle déplace des éléments de a à b 
ou effectue des rotations sur a selon certaines conditions 
(par exemple, si l'index est 0 ou l'index est le dernier). 
Si l'index de l'élément dans b est supérieur à un certain multiple du seizième, 
elle effectue une rotation sur b.

trie_mediane_max(t_stack *p, int seizieme): Cette fonction est le contrôleur 
principal qui orchestre les trois fonctions ci-dessus. 
Elle déplace d'abord certains éléments de a à b et effectue des rotations 
sur a et b en fonction de la comparaison de l'index de chaque élément 
avec certains multiples du seizième. 
Ensuite, elle appelle trie_seizieme_max_botom, trie_seizieme_max_mid 
et trie_seizieme_max_top pour trier les différentes parties de la pile.
*/
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
