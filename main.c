#include"fct.h"
#include"fct_main.h"

int main(){
	time_t t_start, t_end;
	t_start=time(NULL);
  srand(time(NULL));
  game_t game;
  initialisation(&game);
  while(game.end==0){
    display(&game);
    update(&game);
    t_end=time(NULL);
    game.timer=(unsigned long)t_end-t_start;
    	if(game.timer>((game.height*game.width)*2)){
    	game.end=1;
  	}
  }
  display(&game);
  the_record(game);
}


