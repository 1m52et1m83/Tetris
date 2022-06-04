#include"fct.h"
#include"fct_main.h"


void initialisation(game_t* game){//permet d'initialiser le jeu
  init_grid(game);
  game->end = 0;
  game->score=0;
}


void display(game_t* game){//permet d'afficher la grille
  display_grid(game);
}


void update(game_t* game){//permet de mettre à jour le jeu et ses variables
  placement(game);
  remove_line(game);
  end(game);
}
