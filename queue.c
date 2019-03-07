/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:36:11 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 21:15:47 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int isEmpty_q(struct s_queue *queue)
{
	return (!queue->first);
}

struct s_queue *init_q(void)
{
	struct s_queue *new;

	new = (struct s_queue*)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_qnode *new_node;

	new_node = (struct s_qnode*)malloc(sizeof(struct s_qnode));
	new_node->content = content;
	new_node->next = NULL;
	if (isEmpty_q(queue))
		queue->first = new_node;
	else
		queue->last->next = new_node;
	queue->last = new_node;
}

void *dequeue(struct s_queue *queue)
{
	struct s_qnode	*first;
	void			*content;

	if (isEmpty_q(queue))
		return (NULL);
	first = queue->first;
	content = first->content;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(first);
	return (content);
}

void *peek_q(struct s_queue *queue)
{
	if (isEmpty_q(queue))
		return (NULL);
	return (queue->first->content);
}

