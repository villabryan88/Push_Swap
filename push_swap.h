/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:35:23 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/05 00:52:14 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack {
	struct s_node	*top;
}					t_stack;

typedef struct		s_qnode {
	void 			*content;
	struct s_qnode	*next;
}					t_qnode;

typedef struct		s_queue {
	struct s_qnode 	*first;
	struct s_qnode 	*last;
}					t_queue;

int					check_repeat(int *nums, int len);
int					is_valid_input(char **str);
int					isEmpty(t_stack *stack);
int					peek(t_stack *stack);
t_stack				*init(void);
t_node				*pop(t_stack *stack);
void				unshift(t_stack *stack, t_node *new_node);
t_node				*new_node(int val);
void				print_stack(t_stack *stack);
void				swap(int i, t_stack **stacks, int ver);
int					push(int i, t_stack **stacks, int ver);
void				rotate(int i, t_stack **stacks, int ver);
void				reverse(int i, t_stack **stacks, int ver);
int					*arr_str_to_int(char **str, int *len);
int					*parse_nums(int ac, char **av, int *len);
void				populate_stack(int *nums, int len, t_stack **stacks);
struct				s_queue *init_q(void);
void				enqueue(struct s_queue *queue, void *content);
void				*dequeue(struct s_queue *queue);
void				*peek_q(struct s_queue *queue);
#endif
