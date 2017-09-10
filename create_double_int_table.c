/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_double_int_table.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:45:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/10 11:36:39 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudo.h"

int		**create_table_sudo(int argc, char **argv)
{
	t_int_for_create var;

	var.tab = NULL;
	var.i = 1;
	var.j = 0;
	var.k = 0;
	if (!(var.tab = (int **)malloc(sizeof(int *) * argc - 1)))
		return (NULL);
	while (var.i < argc)
	{
		if (!(var.tab[var.k] = (int *)malloc(sizeof(int) * 9)))
			return (NULL);
		var.j = 0;
		while (var.j < 9)
		{
			if (is_numeric(argv[var.i][var.j]))
				var.tab[var.k][var.j] = argv[var.i][var.j] - '0';
			else if (is_dot(argv[var.i][var.j]))
				var.tab[var.k][var.j] = 0;
			var.j++;
		}
		var.k++;
		var.i++;
	}
	return (var.tab);
}
