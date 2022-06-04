#ifndef FILE_FCT_H 

	#define FILE_FCT_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#define HEIGHT 10

	typedef struct {
	  int line;
	  int column;
	}coord_t;
	
	typedef struct {
		int blue;
		int green;
		int red;
		}color_t;
		
		typedef struct{
	  coord_t tab[4];
	  color_t color;
	  int num;
	  int height;
	  int width;
	  int orientation;
	}piece_t;
	
	typedef struct {
		char username[10];
		int score;
	}record_t;

	typedef struct {
	  piece_t model[7];
	  piece_t piece;
	  int line;
	  int column;
	  int end;
	  int height;
	  int width;
	  int **grid;
	  int score;
	  int count_full_line;
	  long unsigned timer;
	  long unsigned timer_to_place;
	  record_t record[10];
	  char username[10];
	}game_t;


	void init_grid(game_t* game);
	void create_pieces (game_t* game);
	int random_piece();
	char cube(int column);
	void display_grid(game_t* game);
	void show_piece(game_t* game);
	void end(game_t* game);
	int impossible(game_t* game);
	int no_orientation(game_t* game);
	int read_box(int grid[HEIGHT][HEIGHT],int line,int column);
	int width_piece(game_t game);
	int height_piece(game_t game);
	int verification(game_t* game);
	void put1(game_t* game);
	void line_max(game_t* game);
	void placement(game_t* game);
	int line_full(int** grid, int height,int width,int line);
	int full(game_t* game);
	void remove_line(game_t* game);
	void the_record(game_t game);
	
#endif // ifndef FILE_FCT_H
