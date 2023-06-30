/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_trie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:27:30 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 11:33:20 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
La fonction 'trie_moins_de_3' sert à trier des listes de taille 2 ou 3. 
Elle reçoit en paramètre une pile et une position minimum. 
Elle effectue différentes instructions en fonction de la taille de la pile 
et la position minimum.

La fonction 'order' vérifie si une liste chaînée de nœuds est triée 
dans l'ordre croissant à partir d'un certain nœud. 
Elle parcourt la liste depuis le nœud courant jusqu'au nœud minimum et 
vérifie si les indices des nœuds sont en ordre croissant. 
Si un nœud avec un index plus grand que le nœud courant est trouvé, 
la fonction retourne 1, indiquant que la liste n'est pas dans l'ordre. 
Sinon, elle retourne 0.

'pa_est_il_trier' détermine si une pile est triée ou non.
Elle utilise la fonction 'find_min' pour trouver le nœud avec l'index minimum 
et la fonction 'order' pour vérifier si la liste est dans l'ordre. 
Si la pile n'est pas dans l'ordre, la fonction retourne la position 
du nœud minimum (multipliée par -1 et réduite de 1). 
Sinon, elle retourne la position du nœud minimum.

La fonction 'cout_placement' calcule la distance entre une position donnée 
et la position médiane d'une liste de taille donnée. 
Si la position est plus grande que la moitié de la taille, 
la fonction retourne la différence entre la position et la taille. 
Sinon, elle retourne la position.

Enfin, 'faire_r_ou_rr' effectue un certain nombre d'opérations de rotation 
ou de rotation inverse sur une pile donnée, en fonction de la position donnée. 
La direction de rotation est déterminée par la valeur de retour 
de 'cout_placement'. La pile sur laquelle les opérations sont effectuées 
est déterminée par le paramètre 'ab'.
*/
void	trie_moins_de_3(t_stack *pil, int p_min)
{
	if (!pil || !p_min)
		return ;
	if (pil->len_total == 2 || (pil->len_a == 3 && p_min == -2))
		return (use_instruction(TRUE, pil, 1, SA));
	else if (pil->len_a == 3 && p_min == -3)
		return (use_instruction(TRUE, pil, 2, RA, SA));
	else if (pil->len_a == 3 && p_min == -1)
		return (use_instruction(TRUE, pil, 2, RRA, SA));
	else if (p_min > 0)
		return (faire_r_ou_rr(pil, p_min, STACK_A));
}

static int	order(t_noeud *tete, t_noeud *min, t_noeud*c)
{
	t_noeud	*index;

	index = c;
	while (index != min)
	{
		if (c->index > index->index)
			return (1);
		if (index->next == NULL)
			index = tete;
		else
			index = index->next;
	}
	return (0);
}

int	pa_est_il_trier(t_stack *pils)
{
	t_noeud	*current;
	t_noeud	*min;

	if (!pils || pils->a == NULL)
		return (0);
	min = find_min(pils->a);
	current = pils->a;
	while (current)
	{
		if (order(pils->a, min, current))
			return ((-1 * min->pos) - 1);
		current = current->next;
	}
	return (min->pos);
}

//calcule la distance d un placement en fct de la pos
static int	cout_placement(int pos, int len)
{
	if (pos > len / 2)
		return (pos - len);
	return (pos);
}

void	faire_r_ou_rr(t_stack *p, int pos, int ab)
{
	int	res;

	if (ab)
		res = cout_placement(pos, p->len_a);
	else
		res = cout_placement(pos, p->len_b);
	while (res)
	{
		if (res < 0)
		{
			if (ab)
				use_instruction(TRUE, p, 1, RRA);
			else
				use_instruction(TRUE, p, 1, RRB);
			res++;
		}
		else
		{
			if (ab)
				use_instruction(TRUE, p, 1, RA);
			else
				use_instruction(TRUE, p, 1, RB);
			res--;
		}
	}
}
