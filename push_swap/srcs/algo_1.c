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

/*trie_quart_min(t_stack *p, int quartile): La fonction compare les index des 
éléments sur la pile b au quartile fourni. Si l'index d'un élément est plus 
grand ou plus petit que certaines limites autour du quartile, 
elle exécute une instruction (PA ou RB). Cette fonction semble se concentrer 
sur le tri des éléments du quartile inférieur.

trie_seizieme_mid_extrem(t_stack *p, int huitieme): Cette fonction trie les 
deux piles en fonction d'une fraction fournie de 1/8 (huitieme) du total 
des éléments. Elle exécute certaines instructions (PA, PB, RB, RA ou RRB) 
en fonction de la position des éléments par rapport aux limites 
autour de cette fraction.

trie_seizieme_min_mid(t_stack *p, int siezieme): Cette fonction tri la pile b 
puis la pile a en fonction d'une fraction fournie de 1/16 (siezieme) 
du total des éléments. Elle exécute certaines instructions (PA, RB, PB) 
en fonction de la position des éléments par rapport aux limites 
autour de cette fraction.

trie_mediane_min(t_stack *p, int seizieme): Cette fonction trie les piles en 
fonction d'une médiane fournie, qui est calculée comme 8 fois la 
fraction de 1/16 (seizieme). Cette fonction se concentre sur le tri des 
éléments qui sont en dessous de cette médiane. 
Elle utilise les trois fonctions décrites ci-dessus pour diviser 
davantage le problème en parties plus petites et les trier.
*/
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
