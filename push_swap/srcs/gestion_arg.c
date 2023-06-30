/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:07:33 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 14:40:33 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_atoi  et check max et min int
static int	ft_atoi_check(char *nptr)
{
	long	nbr;
	int		signe;
	size_t	i;

	i = 0;
	nbr = 0;
	signe = 1;
	if (nptr[i] == '-')
	{
		i++;
		signe = -1;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] == '0' && nptr[i + 1] != '\0')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += nptr[i] - '0';
		if (nbr > 2147483647 || nbr * signe < -2147483648)
			return (2);
		i++;
	}
	return (nptr[i] != '\0' || !i);
}

static int	error_arg(char *arg, int val, t_noeud *last_m, int index)
{
	if (ft_atoi_check(arg) >= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (index == 0)
		return (0);
	else if (last_m == NULL)
		return (1);
	else if (last_m->val == val)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	index--;
	return (error_arg(arg, val, last_m->prev, index));
}

t_noeud	*create_and_link_node(t_arg_manager *manager, int z, t_noeud **head)
{
	t_noeud	*new_node;

	new_node = creat_noeud(manager->new_val, z, manager->last_m);
	if (!new_node)
		return (NULL);
	if (manager->last_m)
		manager->last_m->next = new_node;
	else
		*head = new_node;
	return (new_node);
}

t_noeud	*check_arg(int z, int argc, char **argv, t_noeud *head)
{
	t_arg_manager	manager;

	manager.last_m = NULL;
	while ((z + 1) < argc)
	{
		manager.str = ft_strdup(argv[z + 1]);
		if (manager.str == NULL)
			return (NULL);
		manager.token = ft_strtok(manager.str, " ");
		while (manager.token != NULL)
		{
			manager.new_val = ft_atoi(manager.token);
			if (error_arg(manager.token, manager.new_val, manager.last_m, z))
				return (free_lst_noeud(&head));
			manager.last_m = create_and_link_node(&manager, z, &head);
			if (!manager.last_m)
				return (free_lst_noeud(&head));
			manager.token = ft_strtok(NULL, " ");
			z++;
		}
		free(manager.str);
	}
	return (head);
}
