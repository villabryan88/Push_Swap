/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:35:23 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/22 00:30:14 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct		s_cdlst
{
	int				val;
	struct s_cdlst	*next;
	struct s_cdlst	*prev;
	int				lsti;
}					t_cdlst;


int		check_repeat(int *nums, int len);
int		is_valid_input(char **str);

#endif
