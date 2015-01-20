/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ball.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 12:18:39 by pba               #+#    #+#             */
/*   Updated: 2015/01/20 12:43:52 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"
#include <stdlib.h>
#include <time.h>
# include <unistd.h>
# include <stdio.h>

void add_ball(t_ball *ball, char tab[21][61])
{
	srand(time(NULL));

	ball->x = 9;
	ball->y = 29;
	tab[9][29] = 'o';
	ball->lr = ((rand() % 2) * 2) - 1;
	ball->ud = ((rand() % 2) * 2) - 1;
	ball->time = 10;
}
