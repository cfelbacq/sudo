/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_double_int_table.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:45:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/09 14:06:19 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudo.h"

int		**create_table_sudo(int argc, char **argv)
{
	ft_putstr("create_table_sudo start\n");
	int **new_tab;
  	int i;
	int j;
	int k;

	new_tab = NULL;
	i = 1;
	j = 0;
	k = 0;
	if (!(new_tab = (int **)malloc(sizeof(int *) * argc)))
		return (NULL);
	while (i < argc)
	{
		if (!(new_tab[k] = (int *)malloc(sizeof(int) * 9)))
			return (NULL);
		j = 0;
		while (j < 9)
		{
			if (is_numeric(argv[i][j]))
				new_tab[k][j] = argv[i][j] - '0';
			else if (is_dot(argv[i][j]))
				new_tab[k][j] = 0;
			j++;
		}
		k++;
		i++;
	}
	ft_putstr("create_table_sudo OK\n");
	return (new_tab);
}
