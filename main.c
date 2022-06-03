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
    	if(game.timer>((game.height*game.weight)*2)){
    	game.end=1;
  	}
  }
  display(&game);
  printf("Your time is %ld sec\n",game.timer);
  printf("Tell me your name\n");
  scanf("%s",game.username);
  FILE * fichier = fopen("record.txt","r");
  if(fichier==NULL){
  	exit(1);
  }
  fscanf(fichier,"%s %d",game.record[0].username,&game.record[0].score);
  printf("name : %s\nscore : %d\n",game.record[0].username,game.record[0].score);
  fclose(fichier);
  game.score=180;
  if(game.score>game.record[0].score){
  	fichier=fopen("record.txt","w");
  	fseek(fichier, 0, SEEK_SET);
  	fprintf(fichier,"%s %d\n",game.username,game.score);
  	fseek(fichier, 0, SEEK_SET);
  	fclose(fichier);
  }
}


