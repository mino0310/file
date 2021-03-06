/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:27:08 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:27:09 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_rader_line(t_game *game, t_pos origin, t_pos target)
{
	double	dx;
	double	dy;
	double	step;

	dx = target.x - origin.x;
	dy = target.y - origin.y;
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(target.x - origin.x) > 1
			|| fabs(target.y - origin.y) > 1)
	{
		if (origin.x < 0 || origin.x >= game->win.width
				|| origin.y < 0 || origin.y >= game->win.height)
		{
			origin.x += dx;
			origin.y += dy;
			continue;
		}
		game->img.data[to_coord(game, origin.x, origin.y)] = game->line.color;
		origin.x += dx;
		origin.y += dy;
	}
}

double	to_proper_coord(t_game *game, double origin, int x_or_y)
{
	if (x_or_y == 0)
		return (origin * game->common_tsize * game->map.columns
				/ game->win.width);
	else
		return (origin * game->common_tsize * game->map.rows
				/ game->win.height);
}

void	make_rader(t_game *game)
{
	t_pos		pos[2];
	double		distance;

	game->ray.angle = game->seek_angle / 2 * -1;
	while (game->ray.angle < game->seek_angle / 2)
	{
		game->wall.angle = game->player.rot_angle + game->ray.angle;
		if (game->wall.angle < 0)
			game->wall.angle += 360;
		else if (game->wall.angle > 360)
			game->wall.angle -= 360;
		distance = shoot_ray(game);
		set_pos(&pos[0], game->player.x / MINIMAP_RATIO,
				game->player.y / MINIMAP_RATIO);
		set_pos(&pos[1], game->wall.x / MINIMAP_RATIO,
				game->wall.y / MINIMAP_RATIO);
		game->line.color = 0x0000a1;
		make_line(game, pos[0], pos[1]);
		game->ray.angle += 0.06;
	}
}
