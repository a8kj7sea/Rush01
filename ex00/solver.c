/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibathamn <ibrahim.athamnah@learner.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 05:05:54 by ibathamn          #+#    #+#             */
/*   Updated: 2025/09/20 05:05:54 by ibathamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	find_empty_cell(int board[SIZE][SIZE], int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (board[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	solve_board(int board[SIZE][SIZE], int *constraints)
{
	int	row;
	int	col;
	int	num;

	if (find_empty_cell(board, &row, &col))
	{
		return (is_board_valid(board, constraints));
	}
	num = 1;
	while (num <= SIZE)
	{
		if (is_placement_safe(board, row, col, num))
		{
			board[row][col] = num;
			if (solve_board(board, constraints))
				return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}
