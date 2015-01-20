/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:36:45 by jchichep          #+#    #+#             */
/*   Updated: 2015/01/20 11:56:40 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
# define PONG_H

#include <stdlib.h>

void			ft_puttab(char tab[21][61]);
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
void			add_players(char tab[21][61]);
void			move_player(int joueur, int direction, int *pos, char tab[21][61]);

#endif
