/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:10:23 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:30:06 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *pils, int affichage)
{
	if (affichage)
		ft_printf("rr\n");
	ra(pils, 0);
	rb(pils, 0);
}

void	rb(t_stack *pils, int affichage)
{
	t_noeud	*first;
	t_noeud	*last;

	if (affichage)
		ft_printf("rb\n");
	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	last = get_last_noeud(pils->b);
	first = pils->b;
	pils->b = first->next;
	pils->b->prev = 0;
	first->next = 0;
	last->next = first;
	first->prev = last;
	first->pos = last->pos + 1;
	adjusted_pos(-1, pils->b);
}

void	ra(t_stack *pils, int affichage)
{
	t_noeud	*first;
	t_noeud	*last;

	if (affichage)
		ft_printf("ra\n");
	if (!pils || pils->a == 0 || pils->len_a <= 1)
		return ;
	last = get_last_noeud(pils->a);
	first = pils->a;
	pils->a = first->next;
	pils->a->prev = 0;
	first->next = 0;
	last->next = first;
	first->prev = last;
	first->pos = last->pos + 1;
	adjusted_pos(-1, pils->a);
}
