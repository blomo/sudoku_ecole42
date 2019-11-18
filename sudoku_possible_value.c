/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_possible_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:48:37 by wgorold           #+#    #+#             */
/*   Updated: 2019/03/10 05:49:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_possible_value.h"

void	remove_line(int *mat, int *out, int target)
{
	int line;
	int idx;
	int nbr;

	line = (target / 9) * 9;
	idx = 0;
	while (idx < 9)
	{
		nbr = mat[line + idx];
		if (nbr != 0)
		{
			out[nbr] = 0;
		}
		idx++;
	}
}

void	remove_col(int *mat, int *out, int target)
{
	int col;
	int idx;
	int nbr;

	col = (target % 9);
	idx = 0;
	while (idx < 9)
	{
		nbr = mat[col + idx * 9];
		if (nbr != 0)
		{
			out[nbr] = 0;
		}
		idx++;
	}
}

void	remove_sqt(int *mat, int *out, int target)
{
	int sqt;
	int idx;
	int idx_sup;
	int nbr;

	sqt = (((target / 9) * 9) / 27) * 27 + ((target % 9) / 3) * 3;
	idx = 0;
	idx_sup = 0;
	while (idx_sup < 3)
	{
		idx = 0;
		while (idx < 3)
		{
			nbr = mat[(sqt + 9 * idx_sup) + idx];
			if (nbr != 0)
			{
				out[nbr] = 0;
			}
			idx++;
		}
		idx_sup++;
	}
}

int		*possible_value(int *mat, int target)
{
	int *out;
	int idx;

	out = malloc(10 * 4);
	out[0] = (mat[target] != 0) ? 1 : 0;
	if (out[0] == 1)
	{
		return (out);
	}
	idx = 1;
	while (idx < 10)
	{
		out[idx++] = 1;
	}
	remove_line(mat, out, target);
	remove_col(mat, out, target);
	remove_sqt(mat, out, target);
	return (out);
}

int		**mat_possible_value(int *mat)
{
	int idx;
	int **pos;
	int *tmp;

	pos = malloc(81 * 8);
	idx = 0;
	while (idx < 81)
	{
		tmp = possible_value(mat, idx);
		pos[idx] = tmp;
		idx++;
	}
	return (pos);
}
