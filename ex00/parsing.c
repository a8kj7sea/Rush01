/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibathamn <ibrahim.athamnah@learner.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 05:09:24 by ibathamn          #+#    #+#             */
/*   Updated: 2025/09/20 05:09:24 by ibathamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	is_valid_input(char c, int count)
{
	if (count < 16)
	{
		if (c >= '1' && c <= ('0' + SIZE))
			return (1);
	}
	if (c == ' ')
		return (1);
	return (0);
}

static int	fill_constraints(char *input, int *constraints, int *count)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!is_valid_input(input[i], *count))
			return (0);
		if (input[i] >= '1' && input[i] <= ('0' + SIZE))
		{
			constraints[*count] = input[i] - '0';
			(*count)++;
		}
		i++;
	}
	return (1);
}

int	*parse_constraints(char *input_string)
{
	int	*constraints;
	int	count;

	constraints = (int *)malloc(sizeof(int) * (SIZE * SIZE));
	if (!constraints)
		return (NULL);
	count = 0;
	if (!fill_constraints(input_string, constraints, &count))
	{
		free(constraints);
		return (NULL);
	}
	if (count != 16)
	{
		free(constraints);
		return (NULL);
	}
	return (constraints);
}
