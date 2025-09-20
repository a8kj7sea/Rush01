/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibathamn <ibrahim.athamnah@learner.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 05:02:50 by ibathamn          #+#    #+#             */
/*   Updated: 2025/09/20 05:02:50 by ibathamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>

# define SIZE 4

int		*parse_constraints(char *input_string);

void	initialize_board(int board[SIZE][SIZE]);
void	print_board(int board[SIZE][SIZE]);
void	print_error(void);

int		is_placement_safe(int board[SIZE][SIZE], int row, int col, int num);
int		is_board_valid(int board[SIZE][SIZE], int *constraints);

int		solve_board(int board[SIZE][SIZE], int *constraints);

#endif
