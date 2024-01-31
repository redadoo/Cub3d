/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:21:39 by edoardo           #+#    #+#             */
/*   Updated: 2024/01/31 15:16:33 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

bool draw_vert_line(int x, int y1, int y2, t_vector3 color, t_game *game)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= game->window.size.y  || x < 0 || x >= game->window.size.x) return 0; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= game->window.size.x) y2 = game->window.size.y - 1; //clip

	int color_value = create_trgb(10, color.x, color.y, color.z);

	// Disegna la linea pixel per pixel
	for (int y = y1; y <= y2; y++)
	{
		mlx_pixel_put(game->mlx, game->window.reference, x, y, color_value);
	}
	return true;
}

bool draw_rectangle(int x1, int y1, int x2, int y2, t_vector3 color, t_game *game)
{
    // Ensure x1 is less than x2 and y1 is less than y2
    if (x2 < x1) { int temp = x1; x1 = x2; x2 = temp; }
    if (y2 < y1) { int temp = y1; y1 = y2; y2 = temp; }

    // Clip the rectangle to the screen boundaries
    if (x2 < 0 || x1 >= game->window.size.x || y2 < 0 || y1 >= game->window.size.y) return false;
    if (x1 < 0) x1 = 0;
    if (x2 >= game->window.size.x) x2 = game->window.size.x - 1;
    if (y1 < 0) y1 = 0;
    if (y2 >= game->window.size.y) y2 = game->window.size.y - 1;

    int color_value = create_trgb(10, color.x, color.y, color.z);

    // Draw the rectangle pixel by pixel
    for (int y = y1; y <= y2; y++)
    {
        for (int x = x1; x <= x2; x++)
        {
            mlx_pixel_put(game->mlx, game->window.reference, x, y, color_value);
        }
    }
    return true;
}

bool draw_screen(t_vector3 color, t_game *game)
{
    int color_value = create_trgb(10, color.x, color.y, color.z);

    for (int y = 0; y < game->window.size.y; y++)
    {
        for (int x = 0; x < game->window.size.x; x++)
        {
            mlx_pixel_put(game->mlx, game->window.reference, x, y, color_value);
        }
    }
}