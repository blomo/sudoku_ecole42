/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_io.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:22:05 by wgorold           #+#    #+#             */
/*   Updated: 2019/03/10 23:22:14 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_IO_H
# define SUDOKU_IO_H
# include <unistd.h>
# include <stdlib.h>

void	print_tab_99(int *tab);
int		check_arg(char *str);
int		load_mat_99(char **argv, int *mat);
void	print_possible_val(int *tab);
void	print_possible_mat(int **pos_val, int *mat);
#endif
