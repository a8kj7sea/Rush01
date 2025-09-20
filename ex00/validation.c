/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibathamn <ibrahim.athamnah@learner.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 05:05:41 by ibathamn          #+#    #+#             */
/*   Updated: 2025/09/20 05:05:41 by ibathamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	count_visible_forward(int *line)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = 0;
	while (i < SIZE)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

static int	count_visible_backward(int *line)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = SIZE - 1;
	while (i >= 0)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i--;
	}
	return (visible_count);
}

int	is_placement_safe(int board[SIZE][SIZE], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (board[row][i] == num)
			return (0);
		if (board[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_board_valid(int board[SIZE][SIZE], int *c)
{
	int	i;
	int	j;
	int	line[SIZE];

	i = 0;
	while (i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			line[j] = board[j][i];
		if (count_visible_forward(line) != c[i])
			return (0);
		if (count_visible_backward(line) != c[SIZE + i])
			return (0);
		j = -1;
		while (++j < SIZE)
			line[j] = board[i][j];
		if (count_visible_forward(line) != c[(SIZE * 2) + i])
			return (0);
		if (count_visible_backward(line) != c[(SIZE * 3) + i])
			return (0);
		i++;
	}
	return (1);
}
