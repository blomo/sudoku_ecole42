/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_possible_value.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:25:49 by wgorold           #+#    #+#             */
/*   Updated: 2019/03/10 23:25:56 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_POSSIBLE_VALUE_H
# define SUDOKU_POSSIBLE_VALUE_H
# include <stdlib.h>

void	remove_line(int *mat, int *out, int target);
void	remove_col(int *mat, int *out, int target);
void	remove_sqt(int *mat, int *out, int target);
int		*possible_value(int *mat, int target);
int		**mat_possible_value(int *mat);
#endif
