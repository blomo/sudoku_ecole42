/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:49:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/03/10 05:49:48 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_io.h"

void	print_tab_99(int *tab)
{
	char	tmp;
	int		line;
	int		col;

	line = 0;
	col = 0;
	while (line < 9)
	{
		col = 0;
		while (col < 9)
		{
			tmp = tab[col + line * 9] + 48;
			write(1, " ", 1);
			write(1, &tmp, 1);
			col++;
		}
		write(1, "\n", 1);
		line++;
	}
}

int		check_arg(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] < 48 || str[idx] > 57)
		&& str[idx] != '.')
		{
			return (0);
		}
		idx++;
	}
	if (idx != 9 || str[idx] != '\0')
	{
		return (0);
	}
	return (1);
}

int		load_mat_99(char **argv, int *mat)
{
	int line;
	int col;

	line = 0;
	col = 0;
	while (line < 9)
	{
		if (check_arg(argv[line + 1]) == 0)
		{
			return (0);
		}
		col = 0;
		while (col < 9)
		{
			mat[col + line * 9] = (argv[line + 1][col] == '.') ? 0
			: argv[line + 1][col] - 48;
			col++;
		}
		line++;
	}
	return (1);
}

void	print_possible_val(int *tab)
{
	int		idx;
	char	tmp;

	idx = 1;
	while (idx < 10)
	{
		if (tab[idx] == 1)
		{
			tmp = idx + 48;
			write(1, &tmp, 1);
		}
		idx++;
	}
}

void	print_possible_mat(int **pos_val, int *mat)
{
	int		idx;
	char	tmp;

	idx = 0;
	while (idx < 81)
	{
		tmp = idx / 10 + 48;
		write(1, &tmp, 1);
		tmp = idx % 10 + 48;
		write(1, &tmp, 1);
		write(1, " | ", 3);
		tmp = (mat[idx] == 0) ? '?' : (mat[idx] + 48);
		write(1, &tmp, 1);
		write(1, " | ", 3);
		print_possible_val(pos_val[idx]);
		write(1, "\n", 1);
		idx++;
	}
}
