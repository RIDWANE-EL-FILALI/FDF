<img src="https://github.com/RIDWANE-EL-FILALI/FDF/blob/master/img/My%20project-2.png">


# Index :
* [Introduction](#MinilibX)
* [Mlx_init](#Mlx_init)
* [Mlx_new_window()](#Mlx_new_window)
## MinilibX
A small library which implements some basic functions that allow you to quickly open a window and to draw within it.
More specifically, it’s an abstraction of the “X Window System” for Unix platforms.

Recommended watching: “Introduction to MinilibX” and “Introduction to events” on the school intra if you're a part of the 42 cursus.
## Mlx_init()
```
#include <mlx.h>

void *mlx_ptr;
mlx_ptr = mlx_init();
```
#### installation :
you should include `mlx.h` after you install mlx
for the installation part checkout this guy [MinilibX installation](https://github.com/42Paris/minilibx-linux)
#### include file :
`mlx.h` should be included for a correct use of the MiniLibX API. It only contains function prototypes, no structs are needed.
#### library functions :
First of all, you need to initialize the connection between your software and the display. Once this connection is established, you’ll be able to use other MiniLibX functions to send the graphical orders, like “I want to draw a yellow pixel in this window” or “did the user hit a key?”.
The `mlx_init` function will create this connection. No parameters are needed, and it will return a `void *` identifier, used for further calls to the library routines.
#### RETURN VALUE :
If `mlx_init` fails to set up the connection to the graphical system, it will return `NULL`, otherwise a non-null pointer is returned as a connection identifier.
## Mlx_new_window()
#### PROTOTYPE:
````
void  * mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
````
#### DESCRIPTION:
The `mlx_new_window` function creates a new window on the screen, using the `size_x` and `size_y` parameters to determine its size, and `title` as the text that should be displayed in the window’s title bar.
The `mlx_ptr` parameter is the connection identifier returned by `mlx_init` .
`mlx_new_window` returns a `void *` window identifier that can be used by other MiniLibX calls.
Note that the MiniLibX can handle an arbitrary number of separate windows.
#### Return Values:
If `mlx_new_window` fails to create a new window (for wathever reason), it will return `NULL`, otherwise a non-null pointer is returned as a window identifier.
## Mlx_clear_window()
#### PROTOTYPE:
````
int     mlx_clear_window(void *mlx_ptr, void *win_ptr);
````
#### DESCRIPTION:
clear the window in black.
#### Return Values:
it returns nothing.
## Mlx_destroy_window()
#### PROTOTYPE:
````
int     mlx_destroy_window(void *mlx_ptr, void *win_ptr);
````
#### DESCRIPTION:
destroy the given window
#### Return Values:
it returns nothing.
## mlx_pixel_put()
#### PROTOTYPE:
````
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
````
#### DESCRIPTION:
The `mlx_pixel_put` function draws a defined pixel in the window `win_ptr` using the (`x`,`y`) coordinates, and the specified color.
The origin (`0`,`0`) is the upper left corner of the window, the X and Y axis respectively pointing right and down.
The connection identifier, `mlx_ptr`, is needed
## mlx_string_put()
#### PROTOTYPE:
````
int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
````
#### DESCRIPTION:
Parameters for `mlx_string_put` have the same meaning. Instead of a simple pixel, the specified string will be displayed at (`x`,`y`).
## mlx_new_image()
#### PROTOTYPE:
````
void          * mlx_new_image(void *mlx_ptr, int width, int height);
````
#### DESCRIPTION:
`mlx_new_image` creates a new image in memory. It returns a `void *` identifier needed to manipulate this image later. It only needs the size of the image to be created, using the `width` and `height` parameters, and the `mlx_ptr` connection identifier.

The user can draw inside the image (see below), and can dump the image inside a specified window at any time to display it on the screen. This is done using `mlx_put_image_to_window`. Three identifiers are needed here, for the connection to the display, the window to use, and the image (respectively `mlx_ptr`, `win_ptr` and `img_ptr`). The (x, y) coordinates define where the image should be placed in the window.
## mlx_get_data_addr()
#### PROTOTYPE:
````
char          * mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
````
#### DESCRIPTION:
`mlx_get_data_addr` returns information about the created image, allowing a user to modify it later.

The `img_ptr` parameter specifies the image to use. The three next parameters should be the addresses of three different valid integers.

`bits_per_pixel` will be filled with the number of bits needed to represent a pixel color (also called the depth of the image).

`size_line` is the number of bytes used to store one line of the image in memory. This information is needed to move from one line to another in the image.

`endian` tells you wether the pixel color in the image needs to be stored in little endian `endian == 0`, or big endian `endian == 1`.
#### RETURN VALUE:
returns a `char *` address that represents the beginning of the memory area where the image is stored.
From this adress, the first `bits_per_pixel` bits represent the color of the first pixel in the first line of the image. The second group of `bits_per_pixel` bits represent the second pixel of the first line, and so on. Add `size_line` to the adress to get the beginning of the second line. You can reach any pixels of the image that way.
## mlx_put_image_to_window()
#### PROTOTYPE:
````
int             mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
````
#### DESCRIPTION:
The user can draw inside the image (see below), and can dump the image inside a specified window at any time to display it on the screen. This is done using `mlx_put_image_to_window`










































