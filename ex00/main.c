/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibathamn <ibrahim.athamnah@learner.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 05:03:52 by ibathamn          #+#    #+#             */
/*   Updated: 2025/09/20 05:03:52 by ibathamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	int	board[SIZE][SIZE];
	int	*constraints;

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	constraints = parse_constraints(argv[1]);
	if (!constraints)
	{
		print_error();
		return (1);
	}
	initialize_board(board);
	if (solve_board(board, constraints))
	{
		print_board(board);
	}
	else
	{
		print_error();
	}
	free(constraints);
	return (0);
}
