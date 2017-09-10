/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:39:00 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/10 11:37:25 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudo.h"

int		check_len_argv(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != 9)
			return (0);
		i++;
	}
	return (1);
}

int		check_char_argv(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!is_numeric(argv[i][j]) && !is_dot(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_argv(int argc, char **argv)
{
	if (!(check_len_argv(argc, argv)))
		return (0);
	if (!(check_char_argv(argc, argv)))
		return (0);
	return (1);
}
