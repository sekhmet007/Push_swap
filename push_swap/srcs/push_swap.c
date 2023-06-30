/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <ecullier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:34:08 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:27:15 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	trie_res(t_stack *pils)
{
	int		trie_res;

	trie_res = pa_est_il_trier(pils);
	if (trie_res > 0 || pils->len_total <= 3)
		trie_moins_de_3(pils, trie_res);
	else if (trie_res && pils->len_total <= 25)
		trie_moyen(pils);
	else if (trie_res)
		trie_rapide(pils);
}

int	main(int argc, char **argv)
{
	t_stack	*pils;

	if (argc == 1)
		return (0);
	if (init_struct(&pils, argc, argv))
		return (1);
	trie_res(pils);
	free_struct_stack(&pils);
	return (0);
}
