/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:16:32 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:16:33 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_cardinal(t_game *game)
{
	if (game->wall.what_hit == VERT_HIT)
	{
		if (game->wall.angle > 90 && game->wall.angle < 270)
			game->wall.cardinal = WEST;
		else
			game->wall.cardinal = EAST;
	}
	else if (game->wall.what_hit == HORZ_HIT)
	{
		if (game->wall.angle > 0 && game->wall.angle < 180)
			game->wall.cardinal = SOUTH;
		else
			game->wall.cardinal = NORTH;
	}
}

double	shoot_ray(t_game *game)
{
	double	distance_x;
	double	distance_y;

	distance_y = raycasting_horz(game);
	distance_x = raycasting_vert(game);
	game->wall.x = distance_x < distance_y ? game->ray.vertx : game->ray.horzx;
	game->wall.y = distance_x < distance_y ? game->ray.verty : game->ray.horzy;
	game->wall.what_hit = distance_x < distance_y;
	return (distance_x < distance_y ? distance_x : distance_y);
}

int		check_wall(t_game *game, double x, double y)
{
	int		coord_x;
	int		coord_y;

	coord_x = floor(x / game->common_tsize);
	coord_y = floor(y / game->common_tsize);
	if (coord_x < 0)
		coord_x = 0;
	if (coord_y < 0)
		coord_y = 0;
	if (coord_x > game->map.columns - 1)
		coord_x = game->map.columns - 1;
	if (coord_y > game->map.rows - 1)
		coord_y = game->map.rows - 1;
	if (g_my_map[coord_y][coord_x] == 1)
		return (1);
	return (0);
}
