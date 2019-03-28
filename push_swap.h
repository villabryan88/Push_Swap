/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:35:23 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 23:15:05 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OPP(side) (side + 1) % 2
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
	void			*content;
	struct s_qnode	*next;
}					t_qnode;

typedef struct		s_queue {
	struct s_qnode	*first;
	struct s_qnode	*last;
}					t_queue;

typedef struct		s_block {
	int				side;
	t_node			*start;
	t_node			*end;
	int				len;
	int				part;
	int				sent;
	int				kept;
	t_node			*push_start;
	t_node			*push_end;
	t_node			*keep_start;
	t_node			*keep_end;
	t_node			*first_push;
	t_node			*last_push;
	int				in_pushfield;
	int				push_above;
	int				push_below;
	int				keep_above;
	int				keep_below;
	char			*msg;
	void			*set_var;
	int				alone;
	int				min;
	int				max;
}					t_block;

int					check_repeat(int *nums, int len);
int					is_valid_input(char **str);
int					isempty(t_stack *stack);
int					peek(t_stack *stack);
int					peek2(t_stack *stack);
t_stack				*init(void);
t_node				*pop(t_stack *stack);
void				unshift(t_stack *stack, t_node *new_node);
t_node				*new_node(int val);
void				print_stack(t_stack *stack);
int					swap(int i, t_stack **stacks, int ver);
int					push(int i, t_stack **stacks, int ver);
int					rotate(int i, t_stack **stacks, int ver);
int					reverse(int i, t_stack **stacks, int ver);
int					*arr_str_to_int(char **str, int *len);
int					*parse_nums(int ac, char **av, int *len, int *debug);
void				populate_stack(int *nums, int len, t_stack **stacks);
struct s_queue		*init_q(void);
void				enqueue(struct s_queue *queue, void *content);
void				*dequeue(struct s_queue *queue);
void				*peek_q(struct s_queue *queue);
int					stack_len(t_stack *stack);
void				print_stacks(t_stack **stacks, int debug);
int					bigger_than(t_stack *stack, void *p_part,
									t_stack *og, int len);
int					find_best_part(t_node *iter, t_block *block);
void				assign_best_partition(t_block *block);
int					block_iter(t_block *block, int (*f)(t_node*, t_block*));
int					inc_comp(t_node *iter, t_block *block);
int					dec_comp(t_node *iter, t_block *block);
int					set_remain_start(t_node *iter, t_block *block);
int					above_than(t_node *iter, t_block *block);
void				set_block(t_stack **stacks, t_block *block);
t_node				*block_iter_find(t_block *block, char *var_name,
										int (*f)(t_node*, t_block*));
int					iter_stop();
int					iter_count();
int					iter_continue();
int					piece_iter(t_node *start, t_node *end, t_block *block,
										int (*f)(t_node*, t_block*));
int					can_push(t_node *iter, t_block *block);
int					can_pushkeep(t_node *iter, t_block *block);
int					in_block(t_node *find, t_block *block);
int					in_field(t_node *find, t_node *start, t_node *end);
t_node				*next_push(t_block *block);
t_node				*prev_push(t_block *block);
int					block_min(t_block *block);
int					block_max(t_block *block);
int					piece_len(t_node *start, t_node *end);
int					error(void);
int					ko(void);
char				*stack_convert_string(t_stack *stack);
void				print_block(t_block *block, int	debug);
void				stack_rotate_iter(t_stack **stacks, t_block *block,
										int (*f)(t_stack**, t_block*));
void				stack_reverse_iter(t_stack **stacks, t_block *block,
										int (*f)(t_stack**, t_block*));
int					is_block_sorted(t_block block);
int					find_start(t_stack **stacks, t_block *block);
int					if_top_push(t_stack **stacks, t_block *block);
void				push_direction(t_stack **stacks, t_block *block,
									char *direction);
void				push_top(t_stack **stacks, t_block *block, int debug);
void				quicksort(t_stack **stacks, t_block *block, int debug);

#endif
