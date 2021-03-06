/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:14:57 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:14:58 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_s_a(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.move_speed
		* cos(to_radian((game->player.rot_angle + 45)));
	new_y = game->player.y - game->player.move_speed
		* sin(to_radian((game->player.rot_angle + 45)));
	if (move_check(game, game->player.rot_angle - 135)
			&& !check_sprite(game, new_x, new_y)
			&& new_x < game->common_tsize * game->map.columns
			&& new_y < game->common_tsize * game->map.rows
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_s_d(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.move_speed
		* cos(to_radian((game->player.rot_angle - 45)));
	new_y = game->player.y - game->player.move_speed
		* sin(to_radian((game->player.rot_angle - 45)));
	if (move_check(game, game->player.rot_angle - 225)
			&& !check_sprite(game, new_x, new_y)
			&& new_x < game->common_tsize * game->map.columns
			&& new_y < game->common_tsize * game->map.rows
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_s(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.move_speed
		* cos(to_radian((game->player.rot_angle)));
	new_y = game->player.y - game->player.move_speed
		* sin(to_radian((game->player.rot_angle)));
	if (move_check(game, game->player.rot_angle - 180)
			&& !check_sprite(game, new_x, new_y)
			&& new_x < game->common_tsize * game->map.columns
			&& new_y < game->common_tsize * game->map.rows
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
