/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:10:03 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:38:20 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *pils, int affichage)
{
	t_noeud	*second;
	t_noeud	*first;

	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	if (affichage)
		ft_printf("sb\n");
	first = pils->b;
	second = pils->b->next;
	first->pos = 1;
	second->pos = 0;
	first->prev = second;
	second->prev = 0;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	pils->b = second;
}

void	sa(t_stack *pils, int affichage)
{
	t_noeud	*second;
	t_noeud	*first;

	if (!pils || pils->a == 0 || pils->len_a <= 1)
		return ;
	if (affichage)
		ft_printf("sa\n");
	first = pils->a;
	second = pils->a->next;
	first->pos = 1;
	second->pos = 0;
	first->prev = second;
	second->prev = 0;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	pils->a = second;
}

void	ss(t_stack *pils, int affichage)
{
	if (affichage)
		ft_printf("ss\n");
	sa(pils, 0);
	sb(pils, 0);
}
