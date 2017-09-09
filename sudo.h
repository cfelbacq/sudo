/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:26:57 by cfelbacq          #+#    #+#             */
/*   Updated: 2017/09/09 13:47:43 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDO_H
# define SUDO_H

#include <unistd.h>
#include <stdlib.h>

int		check_len_argv(int argc, char **argv);
int		check_char_argv(int argc, char **argv);
int		check_argv(int argc, char **argv);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_error(void);
void	ft_print_sudo(int **tab);

int		ft_strlen(char *str);
int		is_numeric(char c);
int		is_dot(char c);

int		**create_table_sudo(int argc, char **argv);

#endif
