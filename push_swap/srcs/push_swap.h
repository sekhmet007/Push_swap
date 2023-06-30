/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <ecullier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:16:25 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 14:49:24 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Constante

# define TRUE 1
# define FALSE 0
# define STACK_A 1
# define STACK_B 0
# define PA 0
# define PB 1
# define RRA 2
# define RRB 3
# define RRR 4
# define RA 5
# define RB 6
# define RR 7
# define SA 8
# define SB 9
# define SS 10

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Structure

typedef struct s_noeud
{
	int				val;
	int				index;
	int				pos;
	struct s_noeud	*next;
	struct s_noeud	*prev;
}	t_noeud;

typedef struct s_stack
{
	struct s_noeud	*a;
	struct s_noeud	*b;
	int				len_a;
	int				len_b;
	int				len_total;
}	t_stack;

typedef struct s_arg_manager
{
	t_noeud	*last_m;
	int		new_val;
	char	*token;
	char	*str;
}	t_arg_manager;
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction de PreTrie

void		trie_mediane_min(t_stack *p, int median);
void		trie_mediane_max(t_stack *p, int sezieme);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction de Trie

int			pa_est_il_trier(t_stack *pils);
void		trie_moins_de_3(t_stack *pil, int p_min);
void		trie_moyen(t_stack *p);
void		trie_rapide(t_stack *pil);
void		faire_r_ou_rr(t_stack *p, int position, int ab);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction struct utile

void		adjusted_pos(int decalage, t_noeud *pil);
t_noeud		*get_last_noeud(t_noeud *pil);
t_noeud		*find_min(t_noeud *head);
t_noeud		*find_max(t_noeud *head);
t_noeud		*find_most_close(t_noeud *head_a, t_noeud *noeud_b);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Instructions

void		pa(t_stack *pils, int affichage);
void		pb(t_stack *pils, int affichage);
void		rra(t_stack *pils, int affichage);
void		rrb(t_stack *pils, int affichage);
void		rrr(t_stack *pils, int affichage);
void		ra(t_stack *pils, int affichage);
void		rb(t_stack *pils, int affichage);
void		rr(t_stack *pils, int affichage);
void		sa(t_stack *pils, int affichage);
void		sb(t_stack *pils, int affichage);
void		ss(t_stack *pils, int affichage);

void		use_instruction(int affichage, t_stack *pils, \
int nbr_instruction, ...);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour free

void		*free_struct_stack(t_stack **p);
void		*free_lst_noeud(t_noeud **s);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour Struct

t_noeud		*creat_noeud(int value, int position, t_noeud *previous);
void		parcourir_noeud(t_noeud *noeud, int i, void (*f)(t_noeud *, int));
t_stack		*creat_struct(t_noeud *stack_a);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Arguments

int			init_struct(t_stack **pils, int argc, char **argv);
t_noeud		*check_arg(int z, int argc, char **argv, t_noeud *head);

#endif
