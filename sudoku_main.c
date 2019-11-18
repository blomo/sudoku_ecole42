/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:29:56 by wgorold           #+#    #+#             */
/*   Updated: 2019/03/10 05:48:12 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sudoku_io.h"
#include "sudoku_possible_value.h"

int		find_first_var_position(int **pos_value)
{
	int first_var_pos;

	first_var_pos = 0;
	while (first_var_pos < 81 && pos_value[first_var_pos][0] == 1)
	{
		first_var_pos++;
	}
	return (first_var_pos);
}

void	copie_mat(int *src, int *dest)
{
	int idx;

	idx = 0;
	while (idx < 81)
	{
		dest[idx] = src[idx];
		idx++;
	}
}

int		check_win(int *mat, int *last_sol, int *nbr_sol, int pos)
{
	if (pos == 81)
	{
		copie_mat(mat, last_sol);
		*nbr_sol = *nbr_sol + 1;
		return (1);
	}
	return (0);
}

void	solve_sudoku(int *mat, int *last_sol, int *nbr_sol, int lim_stop)
{
	int **pos_value;
	int first_var_pos;
	int nbr;

	pos_value = mat_possible_value(mat);
	first_var_pos = find_first_var_position(pos_value);
	if (check_win(mat, last_sol, nbr_sol, first_var_pos))
	{
		return ;
	}
	nbr = 0;
	while (++nbr < 10)
	{
		if (pos_value[first_var_pos][nbr] == 1)
		{
			mat[first_var_pos] = nbr;
			solve_sudoku(mat, last_sol, nbr_sol, lim_stop);
			if (lim_stop != -1 && *nbr_sol >= lim_stop)
			{
				return ;
			}
			mat[first_var_pos] = 0;
		}
	}
	return ;
}

int		main(int argx, char **argv)
{
	int *mat;
	int *out;
	int *nbr_sol;

	nbr_sol = malloc(4);
	mat = malloc(9 * 9 * 4);
	out = malloc(9 * 9 * 4);
	if (argx == 10 && load_mat_99(argv, mat))
	{
		solve_sudoku(mat, out, nbr_sol, 2);
		if (*nbr_sol == 1)
		{
			print_tab_99(out);
		}
		else
		{
			write(1, "Error\n", 6);
		}
	}
	else
	{
		write(1, "Error\n", 6);
	}
}
