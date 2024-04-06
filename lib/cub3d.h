/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:47:45 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/06 15:14:59 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __APPLE__
#  include "mlx.h"
#  define UP 13
#  define LEFT 0
#  define DOWN 1
#  define RIGHT 2
#  define EXIT 53
# endif
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
#  define UP 119
#  define LEFT 97
#  define DOWN 115
#  define RIGHT 100
#  define SPACE 32
#  define EXIT 65307
# endif

# define WIN_WIDTH 1200
# define WIN_HEIGHT 600
# define TEXTURE_HEIGHT 64
# define TEXTURE_WIDTH 64
# define KRED "\x1B[31m"

# include "libft/libft.h"
# include "vector/vector.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_window
{
	t_vector2		size;
	void			*reference;
}					t_window;

typedef struct s_sprite
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				img_width;
	int				img_height;
	char			*path;
	int				side;
}					t_sprite;

typedef struct s_player
{
	double			mov_speed;
	t_vector3		pos;
	t_vector2		dir;
}					t_player;

typedef struct s_assets
{
	t_vector3_int	floor_color;
	t_vector3_int	celin_color;
	t_sprite		n_wall;
	t_sprite		s_wall;
	t_sprite		w_wall;
	t_sprite		e_wall;
}					t_assets;

typedef struct s_camera
{
	double			old_x;
	double			old_dir_x;
	double			old_plane_x;
	double			distance;
	double			rot_speed;
	t_vector2		plane;
	t_vector2		dir;
	t_vector2_int	mouse_dir;
	t_vector2_int	mouse_pos;
	t_vector2_int	last_mouse_pos;
	bool			mouse_on_edge;
}					t_camera;

typedef struct s_raycaster
{
	double			camera_x;
	t_vector2		ray_dir;
	t_vector2_int	vec_map;
	t_vector2		side_dist;
	t_vector2		delta_dist;
	t_vector2_int	vec_step;
	t_vector2_int	tex;
	double			perp_wall_dist;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	double			tex_pos;
	double			step;
}					t_raycaster;

typedef struct s_minimap
{
	int				lenght_mini_map;
	int				offset_draw;
	int				title_lenght;
	t_vector3_int	player_color;
	t_vector3_int	title_color;
	t_sprite		sprite;
}	t_minimap;

typedef struct s_game_time
{
	double			time;
	double			old_time;
	double			frame_time;
}	t_game_time;

typedef struct s_game
{
	void			*reference;
	void			*mlx;
	char			**map;
	t_assets		assets;
	t_window		window;
	t_player		player;
	t_camera		camera;
	t_sprite		scene;
	t_raycaster		raycaster;
	t_minimap		mini_map;
	t_game_time		game_time;
}					t_game;
/**
 * @brief Runs the main game loop using the mlx library.
 *
 * @param game Pointer to the game structure.
 */
void				mlx_run(t_game *game);
/**
 * @brief prints the error message (in red) in standard error
 *
 * @param error_message error message to print
 * @param game Pointer to the game structure.
 */
void				error(char *error_message, t_game *game);
/**
 * @brief Initialize the struct t_game to null
 *
 * @param game Pointer to the game structure.
 */
void				init_tgame(t_game *game);
/**
 * @brief Initialize mlx, window and scene
 *
 * @param game Pointer to the game structure.
 */
void				init_mlx(t_game *game);
/**
 * @brief load data in game structure(map,player ...)
 *
 * @param game Pointer to the game structure.
 * @param argv Command-line arguments passed to the program.
 */
void				load_cub3d_data(t_game *game, char **argv);
/**
 * @brief Creates and initializes a new window using the provided parameters.
 *
 * @param mlx Pointer to the mlx instance.
 * @param width Width of the window.
 * @param height Height of the window.
 * @param name String representing the window title.
 * @return Returns a new t_window structure representing the created window.
 */
t_window			ft_new_window(void *mlx, int widht, int height, char *name);
/**
 * @brief Checks if the given file name has the correct ".cub" extension.
 *
 * @param file The name of the file to be checked.
 * @return 0 if the extension is correct, 1 otherwise.
 */
int					check_extension(char *file);
/**
 * @brief Finds the index of the last non-space character in a string.
 *
 * @param map_line A string representing a line of the map.
 * @return The index of the last non-space character in the string.
 */
size_t				last_idx(char *map_line);
/**
 * @brief Trims characters from the beginning
 * and end of a string.
 *
 * @param s1 The string to be trimmed.
 * @param set A set of characters to be trimmed.
 * @return A newly allocated trimmed string.
 */
char				*trim_free(char *s1, char const *set);
/**
 * @brief Compares two strings for equality.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return true if the strings are equal, false otherwise.
 */
bool				streq(char *str1, char *str2);
/**
 * @brief Checks if a string consists of only numeric digits.
 *
 * @param str The string to be checked.
 * @return true if all characters are digits, false otherwise.
 */
bool				is_all_digits(const char *str);
/**
 * @brief Frees allocated memory and exits the game.
 * @param game Pointer to the t_game structure.
 */
int					close_game(t_game *game);
/**
 * @brief Safely destroys a image using mlx_destroy_image if 
 * mlx_ptr and image_ptr are not NULL.
 * @param mlx_ptr Pointer to the  mlx.
 * @param image_ptr Pointer to the image.
 */
void				safe_mlx_destroy_image(void *mlx_ptr, void *image_ptr);
/**
 * @brief Safely destroys a window using mlx_destroy_window if 
 * mlx_ptr and win_ptr are not NULL.
 * @param mlx_ptr Pointer to the mlx context.
 * @param win_ptr Pointer to the window to be destroyed.
 */
void				safe_mlx_destroy_window(void *mlx_ptr, void *win_ptr);
/**
 * @brief Safely destroys the display using mlx_destroy_display if 
 * mlx_ptr is not NULL.
 * @param mlx_ptr Pointer to the mlx context.
 */
void				safe_mlx_destroy_display(void *mlx_ptr);
/**
 * @brief Safely clear a window using mlx_clear_window if
 *  mlx_ptr and win_ptr are not NULL.
 * @param mlx_ptr Pointer to the mlx context.
 * @param win_ptr Pointer to the window to be destroyed.
 */
void				safe_mlx_clear_window(void *mlx_ptr, void *win_ptr);
/**
 * @brief loads textures from information obtained from the map
 * @param game Pointer to the t_game structure.
 */
void				load_texture(t_game *game);
/**
 * @brief Checks if a character represents a valid direction('N','S','E','W').
 * @param ch The character to be checked.
 * @return 1 if the character is a valid direction, 0 otherwise.
 */
int					check_dir(char ch);
/**
 * @brief Checks if an integer falls within a specified range.
 * @param n The integer to be checked.
 * @param lowest The lower bound of the range (inclusive).
 * @param highest The upper bound of the range (inclusive).
 * @return true if the integer falls within the specified range,
	false otherwise.
 */
bool				fits_in_int_range(int n, int lowest, int highest);
/**
 * @brief return char ** size in the form of t_vector2_int
 * @param map A 2D array of characters representing the matrix to be freed.
 */
t_vector2_int		get_map_size(char **map);
/**
 * @brief Creates a integer representation of a color with transparency 
 * (alpha) and RGB components.
 * @param t The transparency (alpha) value, ranging from 0 to 255.
 * @param rgb The RGB color represented as a t_vector3_int structure 
 * containing the red,green, and blue components.
 * @return the color in TRGB format.
 */
int					create_trgb(int t, t_vector3_int rgb);
/**
 * @brief Draws a vertical line with textures on the game scene.
 * @param game Pointer to the game structure containing scene 
 * and raycaster information.
 * @param x The x-coordinate at which the vertical line will be drawn.
 */
void				draw_vert_line_texture(t_game *game, int x);
/**
 * @brief Sets up the raycaster for a given x-coordinate in the game.
 * @param game Pointer to the game structure containing camera, player,
 * and raycaster information.
 * @param x The x-coordinate for which the raycaster is being set up.
 */
void				set_raycaster(t_game *game, int x);
/**
 * @brief Sets the direction of the raycaster based on 
 * the camera's view.
 * @param game Pointer to the game structure containing
 *  player and raycaster information.
 */
void				set_raycaster_dir(t_game *game);
/**
 * @brief Finds the distance to the nearest wall in the 
 * raycaster's path.
 * @param game Pointer to the game structure containing 
 * map and raycaster information.
 */
void				find_distance_tw_wall(t_game *game);
/**
 * @brief Finds the height of the wall to be drawn on the screen.
 * @param game Pointer to the game structure containing raycaster information.
 */
void				find_wall_height(t_game *game);
/**
 * @brief Finds the texture pixel for the wall being drawn.
 * @param game Pointer to the game structure containing 
 * player and raycaster information.
 */
void				find_wall_pixel(t_game *game);
/**
 * @brief Initializes a sprite structure with default values.
 * @return The initialized sprite structure.
 */
t_sprite			init_sprite(void);
/**
 * @brief Creates a new image using the specified mlx pointer.
 * @param mlx_ptr The mlx pointer used to create the new image.
 * @return The new image represented as a t_sprite structure.
 */
t_sprite			new_img(void *mlx_ptr, int width, int height);
/**
 * @brief Sets the color of a pixel at the specified coordinates 
 * in the given image.
 * @param img Pointer to the image (t_sprite structure) where the
 *  pixel will be modified.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color value to be assigned to the pixel in RGBA format.
 */
void				put_pixel(t_sprite *img, int x, int y, uint32_t color);
/**
 * @brief Extracts the color of a pixel at the specified coordinates 
 * from the given image.
 * @param img Pointer to the image (t_sprite structure) from which the 
 * pixel color will be extracted.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return The color value of the pixel at 
 * the specified coordinates in RGBA format.
 */
int					extract_pixel_from_image(t_sprite *img, int x, int y);
/**
 * @brief Initializes the player's position and direction 
 * based on the provided map.
 * @param player Pointer to the player structure to be initialized.
 * @param map The map representing the game environment.
 */
void				init_player(t_player *player, char **map);
/**
 * @brief Checks if the next position is valid within the game map.
 * @param game Pointer to the game structure containing map information.
 * @param x The x-coordinate of the position to be checked.
 * @param y The y-coordinate of the position to be checked.
 * @return 1 if the position is valid (not a wall and within map bounds),
	otherwise 0.
 */
int					check_next_pos(t_game *game, int x, int y);
/**
 * @brief Moves the player based on the specified key input.
 * @param game Pointer to the game structure containing 
 * player and frame time information.
 * @param key The input key representing the desired direction of movement.
 */
void				move_player(t_game *game, int key);
/**
 * @brief Handles keyboard input for the game.
 * @param keycode The keycode of the pressed key.
 * @param game Pointer to the game structure 
 * containing player and game state information.
 * @return Always returns 0 to indicate successful
 * handling of the key event.
 */
int					key_hook(int keycode, t_game *game);
/**
 * @brief Initializes the camera with the specified direction vector.
 * @param camera Pointer to the camera structure to be initialized.
 * @param dir The direction vector indicating the 
 * initial orientation of the camera.
 */
void				init_camera(t_camera *camera, t_vector2 dir);
/**
 * @brief Handle camera rotation
 * @param camera Pointer to the camera structure to be initialized.
 * @param dir The direction vector indicating the 
 * initial orientation of the camera.
 */
int					camera_rotation(int x, int y, t_game *game);
/**
 * @brief Assigns texture path information based on 
 * identifier and string values.
 * @param map The map structure to be populated.
 * @param str1 The first string identifier.
 * @param str2 The second string value.
 */
void				put_info(t_assets *assets, char *str1, char *str2);
/**
 * @brief Parses and assigns coordinates from the map part of the scene file.
 * @param coord The coordinate identifier to be parsed.
 * @param map The map information array.
 * @param game_map The map structure to be populated.
 * @return true if parsing and assignment are successful, false otherwise.
 */
bool				parse_coord(char *coord, char **map, t_assets *assets);
/**
 * @brief Assigns RGB color values to the map structure based on identifier.
 * @param rgb The array containing RGB values as strings.
 * @param game_map The map structure to be populated.
 * @param identifier The identifier for ceiling ("C") or floor ("F") color.
 * @return true if assignment is successful, false otherwise.
 */
bool				assign_rgb(char **rgb, t_assets *assets, char *identifier);
/**
 * @brief Parses and assigns texture and color information from the map part.
 * @param map The map structure to be populated.
 * @param textures_part The array containing texture information strings.
 * @return true if parsing and assignment are successful, false otherwise.
 */
bool				parse_textures(t_assets *assets, char **textures_part);
/**
 * @brief Reads the map file and populates the game structure.
 * @param game The game structure to be populated.
 * @param file_name The name of the scene file.
 * @return true if the scene file is successfully read
 * and parsed, false otherwise.
 */
bool				readmap(t_game *game, char *file_name);
/**
 * @brief Checks if a string has a valid arrangement of surrounding elements.
 * @param map_part A 2D array of characters representing a part of the map.
 * @param i The row index of the current element.
 * @param j The column index of the current element.
 * @return true if the arrangement is valid, false otherwise.
 */
bool				valid_surroundings(char **map_part, size_t i, size_t j);
/**
 * @brief Parses and validates the map.
 *
 * @param map A 2D array of characters representing the map.
 * @return true if the map is valid, false otherwise.
 */
bool				parse_map(char **map);
/**
 * @brief Renders the game scene.
 * @param game Pointer to the game structure containing 
 * scene and rendering information.
 */
void				renderer(t_game *game);
/**
 * @brief Main loop function for the game.
 * @param game Pointer to the game structure
 *  containing scene and game state information.
 * @return Always returns 0 to indicate successful execution of the main loop.
 */
int					main_loop(t_game *game);
/**
 * @brief Checks if a scene file is empty.
 *
 * @param file_name The name of the scene file.
 * @return true if the scene is empty, false otherwise.
 */
bool				is_scene_empty(char *file_name);
/**
 * @brief Retrieves the texture part from the scene file.
 *
 * @return An array containing the texture information from the scene file.
 */
char				**get_textures_part(char **full_map);
/**
 * @brief Gets the number of map lines in the scene file.
 *
 * @return The number of non-empty map lines in the scene file.
 */
int					get_nbr_map_lines(char **full_map);
/**
 * @brief Retrieves the map part from the scene file.
 *
 * @param file_name The name of the scene file.
 * @return An array containing the map information from the scene file.
 */
char				**get_map_part(char **full_map);
void				draw_quad(t_sprite *sprite, t_vector2_int of, int l, int c);
void				draw_minimap(t_game *game);
void				set_vector2_int(t_vector2_int *v, int x, int y);
#endif