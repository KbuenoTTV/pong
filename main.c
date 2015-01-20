/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgetarrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:00:56 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/20 12:06:38 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pong.h"


static int	kbhit(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return (1);
	}
	return (0);
}

static int	getarrowkey(void)
{
	struct termios	line_police;
	char			c;
	int				d;

	if (ioctl(0, TIOCGETA, &line_police) < 0)
		1 ? (perror("getarrowkey error\n"), exit(1)) : 0;
	if (line_police.c_lflag &= ~(ICANON | ECHO))
		if ((ioctl(0, TIOCSETA, &line_police)) < 0)
			1 ? (perror("getarrowkey error\n"), exit(1)) : 0;
	if ((d = 0), kbhit())
		while ((c = fgetc(stdin)))
		{
			d = (c == 'q' ? 5 : d);
			d = (c == 'w' ? 1 : d);
			d = (c == 65 ? 3 : d);
			d = (c == 66 ? 4 : d);
			d = (c == 's' ? 2 : d);
			if (d)
				return (d);
		}
	return (0);
}

int			main(void)
{
	int key = 0;
	char tab[21][61];
	int j1 = 8;
	int j2 = 8;

	ft_filltab(tab);
	add_players(tab);
	while (key != 5)
	{
		key = getarrowkey();
		if (key == 1)
			move_player(1, -1, &j1, tab);
		else if (key == 2)
			move_player(1, 1, &j1, tab);
		else if (key == 3)
			move_player(2, -1, &j2, tab);
		else if (key == 4)
			move_player(2, 1, &j2, tab);
		system("CLEAR");
		ft_puttab(tab);
		usleep(10000);
	}
	return (0);
}
