/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:10:56 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/28 10:10:59 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *pils, int affichage)
{
	t_noeud	*element;

	if (!pils || pils->a == 0)
		return ;
	if (affichage)
		ft_printf("pb\n");
	element = pils->a;
	pils->a = element->next;
	if (pils->a)
		pils->a->prev = 0;
	element->pos = 0;
	element->next = 0;
	adjusted_pos(-1, pils->a);
	adjusted_pos(1, pils->b);
	element->next = pils->b;
	if (element->next)
		element->next->prev = element;
	pils->b = element;
	pils->len_b = pils->len_b + 1;
	pils->len_a = pils->len_a - 1;
}

void	pa(t_stack *pils, int affichage)
{
	t_noeud	*element;

	if (!pils || pils->b == 0)
		return ;
	if (affichage)
		ft_printf("pa\n");
	element = pils->b;
	pils->b = element->next;
	if (pils->b)
		pils->b->prev = 0;
	element->pos = 0;
	element->next = 0;
	adjusted_pos(-1, pils->b);
	adjusted_pos(1, pils->a);
	element->next = pils->a;
	if (element->next)
		element->next->prev = element;
	pils->a = element;
	pils->len_a = pils->len_a + 1;
	pils->len_b = pils->len_b - 1;
}
