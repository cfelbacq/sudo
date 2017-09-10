/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:26:36 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/10 12:27:58 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudo.h"

int	absent_on_line(int number, int y, int **tab)
{
	int x;

	x = 0;
	while (x < 9)
	{
		if (tab[y][x] == number)
			return (0);
		x++;
	}
	return (1);
}

int	absent_on_column(int number, int x, int **tab)
{
	int y;

	y = 0;
	while (y < 9)
	{
		if (tab[y][x] == number)
			return (0);
		y++;
	}
	return (1);
}

int	absent_on_block(int number, int x, int y, int **tab)
{
	int yy;
	int xx;

	yy = y - (y % 3);
	xx = x - (x % 3);
	y = yy;
	while (y < yy + 3)
	{
		x = xx;
		while (x < xx + 3)
		{
			if (tab[y][x] == number)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid(int **tab, int pos)
{
	int y;
	int x;
	int number;

	y = pos / 9;
	x = pos % 9;
	number = 1;
	if (pos == 9 * 9)
		return (1);
	if (tab[y][x] != 0)
		return (is_valid(tab, pos + 1));
	while (number <= 9)
	{
		if (absent_on_line(number, y, tab) && absent_on_column(number, x, tab) \
				&& absent_on_block(number, x, y, tab))
		{
			tab[y][x] = number;
			if (is_valid(tab, pos + 1))
				return (1);
		}
		number++;
	}
	tab[y][x] = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	int **tab;

	tab = NULL;
	if (argc == 10)
	{
		if (check_argv(argc, argv))
		{
			if ((tab = create_table_sudo(argc, argv)) == NULL)
				return (ft_print_error());
			if (!is_valid(tab, 0))
			{
				ft_free_tab_int(tab);
				return (ft_print_error());
			}
			ft_print_sudo(tab);
			ft_free_tab_int(tab);
		}
		else
			ft_print_error();
	}
	else
		ft_print_error();
	return (0);
}
