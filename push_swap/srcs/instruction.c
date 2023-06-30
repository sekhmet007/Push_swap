/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:11:46 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:26:00 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*adjusted_pos' est une fonction récursive qui ajuste la position de tous 
les nœuds dans une liste chaînée, en ajoutant une valeur de décalage 
spécifique à la position de chaque nœud.

Enfin, 'get_last_noeud' est une autre fonction récursive qui trouve 
et retourne le dernier nœud dans une liste chaînée. 
Elle parcourt la liste jusqu'à ce qu'elle atteigne un nœud qui n'a pas de 
successeur, c'est-à-dire un nœud dont l'attribut 'next' est NULL.
*/

static void	find_instruction(int instruction_id, int affichage, t_stack *pils)
{
	if (instruction_id == 0)
		pa(pils, affichage);
	else if (instruction_id == 1)
		pb(pils, affichage);
	else if (instruction_id == 2)
		rra(pils, affichage);
	else if (instruction_id == 3)
		rrb(pils, affichage);
	else if (instruction_id == 4)
		rrr(pils, affichage);
	else if (instruction_id == 5)
		ra(pils, affichage);
	else if (instruction_id == 6)
		rb(pils, affichage);
	else if (instruction_id == 7)
		rr(pils, affichage);
	else if (instruction_id == 8)
		sa(pils, affichage);
	else if (instruction_id == 9)
		sb(pils, affichage);
	else if (instruction_id == 10)
		ss(pils, affichage);
}

void	use_instruction(int affichage, t_stack *pils, int nbr_instruction, ...)
{
	va_list	all_instruction;

	va_start(all_instruction, nbr_instruction);
	while (nbr_instruction--)
		find_instruction(va_arg(all_instruction, int), affichage, pils);
	va_end(all_instruction);
}

void	adjusted_pos(int decalage, t_noeud *pil)
{
	if (!pil)
		return ;
	pil->pos = pil->pos + decalage;
	adjusted_pos(decalage, pil->next);
}

t_noeud	*get_last_noeud(t_noeud *pil)
{
	if (!pil)
		return (0);
	else if (pil->next == 0)
		return (pil);
	return (get_last_noeud(pil->next));
}
