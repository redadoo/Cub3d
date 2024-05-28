/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:47:45 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 15:28:04 by evocatur         ###   ########.fr       */
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
#  include "mlx_linux/mlx.h"
#  define RIGHT_ARROW 65363
#  define LEFT_ARROW 65361
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define UP 119
#  define LEFT 97
#  define DOWN 115
#  define RIGHT 100
#  define SPACE 32
#  define EXIT 65307
#  define F1 65300
# endif

# define WIN_WIDTH 1200
# define WIN_HEIGHT 600
# define TEXTURE_HEIGHT 64
# define TEXTURE_WIDTH 64
# define KRED "\x1B[31m"

# include "vector/vector.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_window
{
	t_vector2_int	size;
	void			*reference;
}					t_window;

typedef struct s_sprite
{
	void			*img;
	char			*addr;
	int				*text_value;
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
	bool			show_minimap;
	void			*mlx;
	char			**map;
	t_assets		assets;
	t_window		window;
	t_player		player;
	t_camera		camera;
	t_sprite		world;
	t_raycaster		raycaster;
	t_minimap		mini_map;
	t_game_time		game_time;
}					t_game;
/**
 * @brief Runs the main game loop using the mlx library.
 *
 * @param game Pointer to the game structure.
 */
void				mlx_main(t_game *game);
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
void				set_null(t_game *game);
/**
 * @brief Initialize mlx, window and world
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
 * @brief Finds the index of the last non-space character in a string.
 *
 * @param map_line A string representing a line of the map.
 * @return The index of the last non-space character in the string.
 */
int					f_ind(char *map_line);
/**
 * @brief remove characters from the beginning
 * and end of a string.
 *
 * @param s1 The string to be trimmed.
 * @param set A set of characters to be trimmed.
 * @return A newly allocated trimmed string.
 */
void				remove_character(char *s1, char const *set);
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
 * @brief loads sprites from information obtained from the map
 * @param game Pointer to the t_game structure.
 */
void				load_sprites(t_game *game);
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
 * @brief Draws a vertical line with textures on the game world.
 * @param game Pointer to the game structure containing world 
 * and raycaster information.
 * @param x The x-coordinate at which the vertical line will be drawn.
 */
void				draw_screen(t_game *game, int x);
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
void				start_dda(t_game *game);
/**
 * @brief Finds the height of the wall to be drawn on the screen.
 * @param game Pointer to the game structure containing raycaster information.
 */
void				ray_distance(t_game *game);
/**
 * @brief calculate lowest and highest pixel to fill in current stripe
 * @param game Pointer to the game structure containing raycaster information.
 */
void				pixel_to_fill(t_game *game);
/**
 * @brief Finds the texture pixel for the wall being drawn.
 * @param game Pointer to the game structure containing 
 * player and raycaster information.
 */
void				wall_hit(t_game *game);
/**
 * @brief Initializes a sprite structure with default values.
 * @return The initialized sprite structure.
 */
t_sprite			get_empty_sprite(void);
/**
 * @brief Creates a new image using the specified mlx pointer.
 * @param mlx_ptr The mlx pointer used to create the new image.
 * @return The new image represented as a t_sprite structure.
 */
t_sprite			init_img(void *mlx_ptr, int width, int height);
/**
 * @brief Sets the color of a pixel at the specified coordinates 
 * in the given image.
 * @param img Pointer to the image (t_sprite structure) where the
 *  pixel will be modified.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color value to be assigned to the pixel in RGBA format.
 */
void				draw_pixel(t_sprite img, int x, int y, int color);
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
 * @brief Parses and assigns coordinates from the map part of the world file.
 * @param coord The coordinate identifier to be parsed.
 * @param map The map information array.
 * @param game_map The map structure to be populated.
 * @return true if parsing and assignment are successful, false otherwise.
 */
bool				get_texture_path(char *coord, char **map, t_assets *assets);

/**
 * @brief Parses and assigns texture and color information from the map part.
 * @param map The map structure to be populated.
 * @param textures_part The array containing texture information strings.
 * @return true if parsing and assignment are successful, false otherwise.
 */

bool				get_info_texture(t_assets *assets, char **textures_part);

/**
 * @brief Reads the map file and populates the game structure.
 * @param game The game structure to be populated.
 * @param file_name The name of the world file.
 * @return true if the world file is successfully read
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

bool				valid_surroundings(char **map_part, t_vector2_int ind);

/**
 * @brief Parses and validates the map.
 *
 * @param map A 2D array of characters representing the map.
 * @return true if the map is valid, false otherwise.
 */

bool				parse_map(char **map);

/**
 * @brief Renders the game world.
 * @param game Pointer to the game structure containing 
 * world and rendering information.
 */

void				renderer(t_game *game);

/**
 * @brief Main loop function for the game.
 * @param game Pointer to the game structure
 *  containing world and game state information.
 * @return Always returns 0 to indicate successful execution of the main loop.
 */

int					main_loop(t_game *game);

/**
 * @brief Checks if a file is empty.
 *
 * @param file_name The name of the world file.
 * @return true if the world is empty, false otherwise.
 */

bool				check_file(char *file_name);

/**
 * @brief Retrieves the texture part from the file.
 *
 * @return An matrix containing the texture information from the file.
 */

char				**read_texture(char **full_map);

/**
 * @brief Gets the number of map lines in the world file.
 *
 * @return The number of non-empty map lines in the world file.
 */

int					file_linecount(char **full_map);

/**
 * @brief Gets the map from file 
 *
 * @return char ** of map
 */

char				**get_map_part(char **full_map);

/**
 * @brief Gets the number of map lines in the world file.
 *
 * @param sprite sprite where draw the quad
 * 
 * @param offset pixel offset
 * 
 * @param lenght quad size
 * 
 * @param color quad color
 */
void				draw_quad(t_sprite	sprite, t_vector2_int offset,
						int lenght, int color);

/**
 * @brief draw minimap
 *
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 */
void				draw_minimap(t_game *game);

/**
 * @brief render floor and celing 
 *
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 * @param x x position of vertical stripes
 */
void				render_background(t_game *game, int x);

/**
 * @brief function to manage the rotation of player view
 *
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 * @param distance distance of view
 */
void				rotate_view(t_game *game, double distance);

/**
 * @brief manage the frame time for the game
 *
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 */
void				manage_time(t_game *game);

/**
 * @brief move the player to he's back.
 *
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 * @param is_ahead is_left is true when player press key (W) on keyboard
 */
void				front_movement(t_game *game, bool is_ahead);

/**
 * @brief move the player to he's right.
 *
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 * @param is_left is_left is true when player press left key(A)
 */
void				lateral_movement(t_game *game, bool is_left);

/**
 * @brief put a image on screen and destroy the image
 * @param game Pointer to the game structure containing 
 * 	world and rendering information.
 * @param i void pointer to the image
 * @param x x image position
 * @param y y image position
 */
void				put_and_destroy_image(t_game *g, void *i, int x, int y);

/**
 * @brief Initializes a texture for a sprite in the cub3d project.
 *
 * @param texture Pointer to the t_sprite structure that holds the texture 
 *                information.
 * @param game Pointer to the game structure containing 
 * world and rendering information.
 */
void				init_sprite(t_sprite *texture, t_game *game);

#endif