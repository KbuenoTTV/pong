/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 12:25:44 by pba               #+#    #+#             */
/*   Updated: 2015/01/20 12:44:36 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pong.h"

void move_ball(t_ball *ball, char tab[21][61])
{
	if (ball->time != 10)
		ball->time--;
	else
	{
		if (ball->x == 1 && ball->ud == -1)
			ball->ud = 1;
		if (ball->x == 18 && ball->ud == 1)
			ball->ud = -1;
		tab[ball->x][ball->y] = ' ';
		ball->x = ball->x + ball->ud;
		tab[ball->x][ball->y] = 'o';
		ball->time = 10;
	}
}
