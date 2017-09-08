#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_print_sudo(int **tab);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_error(void)
{
	ft_putstr("Error\n");
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	ft_putstr(str);
	while (str[i] != '\0')
		i++;
	ft_putstr(" len :");
	ft_putchar(i + '0');
	ft_putchar('\n');
	return (i);
}

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

int		is_numeric(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		is_dot(char c)
{
	if (c == '.')
		return (1);
	return (0);
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
	if (!(new_tab = (int **)malloc(sizeof(int) * argc)))
		return (NULL);
	while (i < 10)
	{
		if (!(new_tab[k] = (int *)malloc(sizeof(int) * 9)))
			return (NULL);
		j = 0;
		while (j < 9)
		{
			ft_putchar(argv[i][j]);
			if (is_numeric(argv[i][j]))
			{
				ft_putchar('a');
				new_tab[k][j] = argv[i][j] - '0';
				ft_putchar(new_tab[k][j] % 10 + '0');
			}
			else if (is_dot(argv[i][j]))
				new_tab[k][j] = 0;
			j++;
		}
		ft_putchar('\n');
		k++;
		i++;
	}
	ft_putchar(new_tab[0][0] % 10 + '0');
	ft_putstr("create_table_sudo OK\n");
	return (new_tab);
}

void	ft_print_sudo(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(tab[i][j] % 10 + '0');
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int **tab;

	tab = NULL;
	if (argc == 10)
	{
		ft_putstr("Nombre d'argument valide\n");
		if (check_argv(argc, argv))
		{
			ft_putstr("check argv OK\n");
			tab = create_table_sudo(argc, argv);
			ft_print_sudo(tab);
		}
	}
	else
		print_error();
	return (0);
}
