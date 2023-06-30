/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:05:20 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:25:21 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*La fonction 'find_min' reçoit un pointeur vers un nœud (head) et parcourt 
l'ensemble de la liste chaînée à partir de ce nœud pour trouver le nœud avec
l'index minimum. Si un nœud avec un index de 0 est trouvé,
il est immédiatement retourné comme étant le minimum.
Si aucun nœud avec un index de 0 n'est trouvé, 
le nœud avec l'index minimum trouvé lors du parcours est retourné.

De même, la fonction 'find_max' parcourt l'ensemble 
de la liste chaînée à partir du nœud de tête pour trouver le nœud 
avec l'index maximum. Contrairement à 'find_min', 
cette fonction ne retourne pas immédiatement si un certain index est trouvé,
mais continue à parcourir jusqu'à la fin de la liste.

La fonction 'find_most_close' est utilisée pour trouver le nœud 
dans la liste 'head_a' qui a l'index le plus proche de l'index du 
nœud 'noeud_b'. Elle parcourt l'ensemble de la liste 'head_a', 
calculant la différence entre l'index de chaque nœud et l'index de 'noeud_b'. 
Le nœud avec la plus petite différence est retourné.

La fonction 'init_struct' est utilisée pour initialiser une structure de pile. 
Elle utilise la fonction 'check_arg' pour obtenir une liste de nœuds à partir 
des arguments de la ligne de commande, puis crée une structure de pile
à partir de cette liste en utilisant la fonction 'creat_struct'. 
Si 'check_arg' ou 'creat_struct' retourne NULL, signifiant qu'une erreur 
s'est produite, la fonction 'init_struct' retourne 1. 
Sinon, elle retourne 0, indiquant que l'initialisation a réussi.
*/
t_noeud	*find_min(t_noeud *head)
{
	t_noeud	*index;
	t_noeud	*res;

	index = head;
	res = head;
	while (index)
	{
		if (index->index < res->index)
			res = index;
		if (res->index == 0)
			return (res);
		index = index->next;
	}
	return (res);
}

t_noeud	*find_max(t_noeud *head)
{
	t_noeud	*index;
	t_noeud	*res;

	index = head;
	res = head;
	while (index)
	{
		if (index->index > res->index)
			res = index;
		index = index->next;
	}
	return (res);
}
//trouve le noeud le plus proche

t_noeud	*find_most_close(t_noeud *head_a, t_noeud *noeud_b)
{
	t_noeud	*res;
	int		diff_index;
	int		buff;
	t_noeud	*index;

	index = head_a;
	diff_index = 0;
	while (index)
	{
		if (noeud_b->index > index->index)
			buff = noeud_b->index - index->index;
		else
			buff = index->index - noeud_b->index;
		if (!diff_index || buff < diff_index)
		{
			res = index;
			diff_index = buff;
		}
		index = index->next;
	}
	return (res);
}
//initialise les structures

int	init_struct(t_stack **pils, int argc, char **argv)
{
	t_noeud	*a;

	a = check_arg(0, argc, argv, NULL);
	if (a == NULL)
		return (1);
	(*pils) = creat_struct(a);
	if ((*pils) == NULL)
		return (1);
	return (0);
}
