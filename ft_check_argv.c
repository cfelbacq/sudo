/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:39:00 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/09 13:42:39 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudo.h"

int		check_len_argv(int argc, char **argv)
{
	ft_putstr("Check len start\n");
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != 9)
			return (0);
		i++;
	}
	ft_putstr("check len OK\n");
	return (1);
}

int		check_char_argv(int argc, char **argv)
{
	ft_putstr("Check char start\n");
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
	ft_putstr("Check char OK\n");
	return (1);
}

int		check_argv(int argc, char **argv)
{
	ft_putstr("check argv start\n");
	if (!(check_len_argv(argc, argv)))
	{
		ft_putstr("Len des arguments invalides\n");
		return (0);
	}
	ft_putstr("taille des arguments valide\n");
	if (!(check_char_argv(argc, argv)))
		return (0);
	ft_putstr("caractere valide dans les arguments\n");
	return (1);
}
