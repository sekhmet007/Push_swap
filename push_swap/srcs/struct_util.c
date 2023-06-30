/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:04:24 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/28 10:04:39 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*La fonction 'parcourir_noeud' est une fonction récursive qui parcourt
une liste chaînée de nœuds, en commençant par le nœud fourni en argument. 
Pour chaque nœud, elle appelle une fonction de rappel (f) en passant le nœud 
et une valeur entière (i). Si le nœud actuel n'a pas de suivant, 
la fonction s'arrête.

La fonction 'ft_noeud_size' calcule récursivement la taille d'une liste
chaînée de nœuds, en commençant par le nœud fourni. Si le nœud fourni est NULL,
la fonction retourne 0. Sinon, elle ajoute 1 à la taille calculée pour 
le reste de la liste.

'put_index' est une fonction récursive utilisée pour attribuer des indices 
aux nœuds d'une liste chaînée. Elle compare la valeur du nœud précédent avec 
celle du nœud courant et ajuste leurs indices en conséquence. Si le nœud 
précédent est NULL, la fonction retourne sans effectuer aucune action.

La fonction 'creat_noeud' est utilisée pour créer un nouveau nœud avec une 
valeur, une position et un nœud précédent donnés. Le nœud est alloué 
dynamiquement et initialisé avec les valeurs fournies, un index de 0 et 
un pointeur suivant de NULL. La fonction 'put_index' est ensuite utilisée 
pour attribuer un index approprié au nouveau nœud. 
Si l'allocation de mémoire pour le nouveau nœud échoue, la fonction retourne 0.

'creat_struct' est utilisée pour créer une nouvelle structure de pile à partir 
d'une liste chaînée de nœuds. La structure est allouée dynamiquement et 
initialisée avec la liste de nœuds fournie, une taille calculée avec 
la fonction 'ft_noeud_size', une liste de nœuds vide pour la pile B, et 
des longueurs appropriées pour les piles A et B et la longueur totale. 
Si l'allocation de mémoire pour la nouvelle structure échoue, 
la liste de nœuds fournie est libérée en utilisant la fonction 
'free_lst_noeud' et la fonction retourne NULL.
*/
void	parcourir_noeud(t_noeud *noeud, int i, void (*f)(t_noeud *, int))
{
	if (!noeud || !f)
		return ;
	f(noeud, i);
	if (!noeud->next)
		return ;
	parcourir_noeud(noeud->next, i, f);
}

int	ft_noeud_size(t_noeud *stack_a)
{
	if (!stack_a)
		return (0);
	return (1 + ft_noeud_size(stack_a->next));
}

void	put_index(t_noeud *prev, t_noeud *current)
{
	if (!prev)
		return ;
	if (prev->val > current->val)
		prev->index++;
	else if (prev->index >= current->index)
		current->index = prev->index + 1;
	put_index(prev->prev, current);
}

t_noeud	*creat_noeud(int value, int pos, t_noeud *prev)
{
	t_noeud	*new_noeud;

	new_noeud = ft_calloc(1, sizeof(t_noeud));
	if (new_noeud == NULL)
		return (0);
	new_noeud->val = value;
	new_noeud->index = 0;
	new_noeud->pos = pos;
	new_noeud->prev = prev;
	new_noeud->next = 0;
	put_index(prev, new_noeud);
	return (new_noeud);
}

t_stack	*creat_struct(t_noeud *stack_a)
{
	t_stack	*new_pil;
	int		len;

	len = ft_noeud_size(stack_a);
	new_pil = ft_calloc(1, sizeof(t_stack));
	if (new_pil == NULL)
		return (free_lst_noeud(&stack_a));
	new_pil->a = stack_a;
	new_pil->b = NULL;
	new_pil->len_a = len;
	new_pil->len_b = 0;
	new_pil->len_total = len;
	return (new_pil);
}
