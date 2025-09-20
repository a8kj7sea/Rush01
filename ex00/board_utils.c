/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibathamn <ibrahim.athamnah@learner.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 05:05:20 by ibathamn          #+#    #+#             */
/*   Updated: 2025/09/20 05:05:20 by ibathamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	initialize_board(int board[SIZE][SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	print_board(int board[SIZE][SIZE])
{
	int		row;
	int		col;
	char	digit;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			digit = board[row][col] + '0';
			write(1, &digit, 1);
			if (col < SIZE - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
