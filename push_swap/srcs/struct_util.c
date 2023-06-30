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
