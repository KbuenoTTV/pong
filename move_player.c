/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:41:10 by jchichep          #+#    #+#             */
/*   Updated: 2015/01/20 12:33:41 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void move_player(int joueur, int direction, int *pos, char tab[21][61])
{
	int y;
	if (joueur == 1)
		y = 2;
	else
		y = 57;
	if (direction == 1 && *pos < 16)
	{
		tab[*pos][y] = ' ';
		tab[*pos + 3][y] = '|';
		++(*pos);
	}
	if (direction == -1 && *pos > 1)
	{
		tab[*pos + 2][y] = ' ';
		tab[*pos - 1][y] = '|';
		--(*pos);
	}
}
