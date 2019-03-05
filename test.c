/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:49:34 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/04 19:32:03 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <ft_printf.h>
#include <stdio.h>
#include <fcntl.h>

int		main()
{
	char *line;
	int		fd;

	fd = open("checker.c", O_RDONLY);
	while(get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
	}

	return (0);
}
