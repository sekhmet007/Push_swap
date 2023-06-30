/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:23:52 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/28 10:23:58 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *pils, int affichage)
{
	if (affichage)
		ft_printf("rrr\n");
	rra(pils, 0);
	rrb(pils, 0);
}

void	rrb(t_stack *pils, int affichage)
{
	t_noeud	*last;

	if (affichage)
		ft_printf("rrb\n");
	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	last = get_last_noeud(pils->b);
	if (last->prev)
		last->prev->next = 0;
	last->prev = 0;
	last->pos = 0;
	adjusted_pos(+1, pils->b);
	last->next = pils->b;
	if (last->next)
		last->next->prev = last;
	pils->b = last;
}

void	rra(t_stack *pils, int affichage)
{
	t_noeud	*last;

	if (affichage)
		ft_printf("rra\n");
	if (!pils || pils->a == 0 || pils->len_a <= 1)
		return ;
	last = get_last_noeud(pils->a);
	if (last->prev)
		last->prev->next = 0;
	last->prev = 0;
	last->pos = 0;
	adjusted_pos(+1, pils->a);
	last->next = pils->a;
	if (last->next)
		last->next->prev = last;
	pils->a = last;
}
