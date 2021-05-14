/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:23:05 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:23:05 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_ceil(t_game *game)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			0);
	set_pos(&pos[1], pos[0].x,
			game->win.height / 2 - (game->wall.realheight / 2));
	game->line.color = game->map.ceil;
	make_line(game, pos[0], pos[1]);
}

void	make_floor(t_game *game)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			game->win.height / 2 + (game->wall.realheight / 2) - 1);
	set_pos(&pos[1], pos[0].x, game->win.height);
	game->line.color = game->map.floor;
	make_line(game, pos[0], pos[1]);
}
