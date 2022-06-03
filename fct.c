#include"fct.h"


void check(void* p,int a){ //pemet de vérifier les fonctions
	if(p==NULL){
		printf("%d ERROR\n",a);
		exit(a);
	}
}

void flush(){ //permet d'éliminer les élément du scanf qui ne sont pas attendu
	int a;
	char b;
	do{
		a=scanf("%c",&b);
	}while(a==1&&b!='\n');
}
	
void init_grid(game_t* game){//permet d'allouer l'espace à la grille et de l'initialiser à 0
	printf("choisir la largeur\n");
	scanf("%d",&game->weight);
	printf("choisir la hauteur\n");
	scanf("%d",&game->height);
	game->height+=4;
	game->grid=malloc(sizeof(int*)*game->height);
	for(int i=0;i<game->height;i++){
		game->grid[i]=malloc(sizeof(int)*game->weight);
    for(int j=0;j<game->weight;j++){
      game->grid[i][j]=0;
    }
  }
}


void create_pieces (game_t* game)//permet de créer la pièce en fonction de la colonne choisi
{
	check(game->grid,2);
	if(game->piece.num>=0&&game->piece.num<6){
  	if(game->piece.num==0){
    	game->piece.tab[1].line=game->piece.tab[0].line;
    	game->piece.tab[1].column=game->piece.tab[0].column+1;
    	game->piece.tab[2].line=game->piece.tab[0].line-1;
    	game->piece.tab[2].column=game->piece.tab[0].column;
    	game->piece.tab[3].line=game->piece.tab[0].line-1;
    	game->piece.tab[3].column=game->piece.tab[0].column+1;
    	game->piece.color.red=255;
    	game->piece.color.green=255;
    	game->piece.color.blue=0;
  	}
  	else if(game->piece.num==1){
  	  if(game->piece.orientation==1){
  	    game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line-2;
  	    game->piece.tab[2].column=game->piece.tab[0].column;
  	    game->piece.tab[3].line=game->piece.tab[0].line-3;
  	    game->piece.tab[3].column=game->piece.tab[0].column;
  	  	game->piece.color.red=0;
    		game->piece.color.green=255;
    		game->piece.color.blue=0;
  	  }
  	  else if(game->piece.orientation==2){
  	    game->piece.tab[1].line=game->piece.tab[0].line;
  	    game->piece.tab[1].column=game->piece.tab[0].column+1;
  	    game->piece.tab[2].line=game->piece.tab[0].line;
  	    game->piece.tab[2].column=game->piece.tab[0].column+2;
  	    game->piece.tab[3].line=game->piece.tab[0].line;
  	    game->piece.tab[3].column=game->piece.tab[0].column+3;
  	    game->piece.color.red=0;
    		game->piece.color.green=255;
    		game->piece.color.blue=0;
  	  }
  	}    
  	else if(game->piece.num==2){
    	if(game->piece.orientation==1){
    	  game->piece.tab[1].line=game->piece.tab[0].line;
    	  game->piece.tab[1].column=game->piece.tab[0].column+1;
    	  game->piece.tab[2].line=game->piece.tab[0].line-1;
    	  game->piece.tab[2].column=game->piece.tab[0].column+1;
    	  game->piece.tab[3].line=game->piece.tab[0].line-1;
    	  game->piece.tab[3].column=game->piece.tab[0].column+2;
    	  game->piece.color.red=255;
    		game->piece.color.green=0;
    		game->piece.color.blue=128;
    	}
    	else if(game->piece.orientation==2){
    	  game->piece.tab[1].line=game->piece.tab[0].line-1;
    	  game->piece.tab[1].column=game->piece.tab[0].column;
    	  game->piece.tab[2].line=game->piece.tab[0].line-1;
    	  game->piece.tab[2].column=game->piece.tab[0].column-1;
    	  game->piece.tab[3].line=game->piece.tab[0].line-2;
    	  game->piece.tab[3].column=game->piece.tab[0].column-1;
    	  game->piece.color.red=255;
    		game->piece.color.green=0;
    		game->piece.color.blue=128;
    	}
  	}
  	else if(game->piece.num==3){
    	if(game->piece.orientation==1){
    	  game->piece.tab[1].line=game->piece.tab[0].line;
    	  game->piece.tab[1].column=game->piece.tab[0].column+1;
    	  game->piece.tab[2].line=game->piece.tab[0].line-1;
    	  game->piece.tab[2].column=game->piece.tab[0].column;
    	  game->piece.tab[3].line=game->piece.tab[0].line-1;
    	  game->piece.tab[3].column=game->piece.tab[0].column-1;
    	  game->piece.color.red=0;
    		game->piece.color.green=255;
    		game->piece.color.blue=255;
    	}
    	else if(game->piece.orientation==2){
    	  game->piece.tab[1].line=game->piece.tab[0].line-1;
    	  game->piece.tab[1].column=game->piece.tab[0].column;
    	  game->piece.tab[2].line=game->piece.tab[0].line-1;
    	  game->piece.tab[2].column=game->piece.tab[0].column-1;
    	  game->piece.tab[3].line=game->piece.tab[0].line-2;
    	  game->piece.tab[3].column=game->piece.tab[0].column-1;
    	  game->piece.color.red=0;
    		game->piece.color.green=255;
    		game->piece.color.blue=255;
    	}
  	}
  	else if(game->piece.num==4){
    	if(game->piece.orientation==1){
    	  game->piece.tab[1].line=game->piece.tab[0].line;
    	  game->piece.tab[1].column=game->piece.tab[0].column+1;
    	  game->piece.tab[2].line=game->piece.tab[0].line;
    	  game->piece.tab[2].column=game->piece.tab[0].column+2;
    	  game->piece.tab[3].line=game->piece.tab[0].line-1;
    	  game->piece.tab[3].column=game->piece.tab[0].column+1;
    	  game->piece.color.red=255;
    		game->piece.color.green=128;
    		game->piece.color.blue=0;
    	}
    	else if(game->piece.orientation==2){
    	  game->piece.tab[1].line=game->piece.tab[0].line-1;
    	  game->piece.tab[1].column=game->piece.tab[0].column;
    	  game->piece.tab[2].line=game->piece.tab[0].line-2;
    	  game->piece.tab[2].column=game->piece.tab[0].column;
    	  game->piece.tab[3].line=game->piece.tab[0].line-1;
    	  game->piece.tab[3].column=game->piece.tab[0].column+1;
    	  game->piece.color.red=255;
    		game->piece.color.green=128;
    		game->piece.color.blue=0;
    	}
    	else if(game->piece.orientation==3){
    	  game->piece.tab[1].line=game->piece.tab[0].line-1;
    	  game->piece.tab[1].column=game->piece.tab[0].column;
    	  game->piece.tab[2].line=game->piece.tab[0].line-1;
   		  game->piece.tab[2].column=game->piece.tab[0].column-1;
    	  game->piece.tab[3].line=game->piece.tab[0].line-1;
    	  game->piece.tab[3].column=game->piece.tab[0].column+1;
    	  game->piece.color.red=255;
    		game->piece.color.green=128;
    		game->piece.color.blue=0;
   	 	}
    	else if(game->piece.orientation==4){
      	game->piece.tab[1].line=game->piece.tab[0].line-1;
      	game->piece.tab[1].column=game->piece.tab[0].column;
      	game->piece.tab[2].line=game->piece.tab[0].line-2;
     		game->piece.tab[2].column=game->piece.tab[0].column;
      	game->piece.tab[3].line=game->piece.tab[0].line-1;
      	game->piece.tab[3].column=game->piece.tab[0].column-1;
      	game->piece.color.red=255;
    		game->piece.color.green=128;
    		game->piece.color.blue=0;
    	}
  	}
  	else if(game->piece.num==5){
  		if(game->piece.orientation==1){
  			game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line-2;
  	    game->piece.tab[2].column=game->piece.tab[0].column;
  	    game->piece.tab[3].line=game->piece.tab[0].line;
  	    game->piece.tab[3].column=game->piece.tab[0].column+1;
  	    game->piece.color.red=255;
    		game->piece.color.green=0;
    		game->piece.color.blue=0;
			}
			else if(game->piece.orientation==2){
				game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line-1;
  	    game->piece.tab[2].column=game->piece.tab[0].column+1;
  	    game->piece.tab[3].line=game->piece.tab[0].line-1;
  	    game->piece.tab[3].column=game->piece.tab[0].column+2;
  	    game->piece.color.red=255;
    		game->piece.color.green=0;
    		game->piece.color.blue=0;
  	  }
  	  else if(game->piece.orientation==3){
				game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line-2;
  	    game->piece.tab[2].column=game->piece.tab[0].column;
  	    game->piece.tab[3].line=game->piece.tab[0].line-2;
  	    game->piece.tab[3].column=game->piece.tab[0].column-1;
  	    game->piece.color.red=255;
    		game->piece.color.green=0;
    		game->piece.color.blue=0;
  	  }
  	  else if(game->piece.orientation==4){
				game->piece.tab[1].line=game->piece.tab[0].line;
  	    game->piece.tab[1].column=game->piece.tab[0].column+1;
  	    game->piece.tab[2].line=game->piece.tab[0].line;
  	    game->piece.tab[2].column=game->piece.tab[0].column+2;
  	    game->piece.tab[3].line=game->piece.tab[0].line-1;
  	    game->piece.tab[3].column=game->piece.tab[0].column;
  	    game->piece.color.red=255;
    		game->piece.color.green=0;
    		game->piece.color.blue=0;
  	  }
  	 }
  	 else if(game->piece.num==6){
  		if(game->piece.orientation==1){
  			game->piece.tab[1].line=game->piece.tab[0].line;
  	    game->piece.tab[1].column=game->piece.tab[0].column+1;
  	    game->piece.tab[2].line=game->piece.tab[0].line-1;
  	    game->piece.tab[2].column=game->piece.tab[0].column+1;
  	    game->piece.tab[3].line=game->piece.tab[0].line-2;
  	    game->piece.tab[3].column=game->piece.tab[0].column+1;
  	    	game->piece.color.red=120;
    		game->piece.color.green=0;
    		game->piece.color.blue=255;
			}
			else if(game->piece.orientation==2){
				game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line;
  	    game->piece.tab[2].column=game->piece.tab[0].column+1;
  	    game->piece.tab[3].line=game->piece.tab[0].line;
  	    game->piece.tab[3].column=game->piece.tab[0].column+2;
  	    game->piece.color.red=120;
    		game->piece.color.green=0;
    		game->piece.color.blue=255;
  	  }
  	  else if(game->piece.orientation==3){
				game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line-2;
  	    game->piece.tab[2].column=game->piece.tab[0].column;
  	    game->piece.tab[3].line=game->piece.tab[0].line-2;
  	    game->piece.tab[3].column=game->piece.tab[0].column+1;
  	    game->piece.color.red=120;
    		game->piece.color.green=0;
    		game->piece.color.blue=255;
  	  }
  	  else if(game->piece.orientation==4){
				game->piece.tab[1].line=game->piece.tab[0].line-1;
  	    game->piece.tab[1].column=game->piece.tab[0].column;
  	    game->piece.tab[2].line=game->piece.tab[0].line-1;
  	    game->piece.tab[2].column=game->piece.tab[0].column-1;
  	    game->piece.tab[3].line=game->piece.tab[0].line-1;
  	    game->piece.tab[3].column=game->piece.tab[0].column-2;
  	    game->piece.color.red=120;
    		game->piece.color.green=0;
    		game->piece.color.blue=255;
  	  }
  	 }
  	   
  }
	for(int i = 0; i<4; i++){
    game->model[i].num = i;
  }
}



int random_piece(){
	return rand()%6;	
}





//----------------DISPLAY-----------------------------------------

char cube(int column){//permet de changer les 0 en vide et les 1 en o
  switch(column)
    {
    case 0: return ' ';
      break;
    case 1: return 'o';
      break;
    case 2: return 'o';
      break;
    case 3: return 'o';
      break;
    case 4: return 'o';
      break;
    case 5: return 'o';
      break;
    case 6: return 'o';
      break;
    case 7: return 'o';
      break;
    }
}


void piece_color(game_t* game){
for(int i=0;i<game->height;i++){
    for(int j=0;j<game->weight;j++){
			if(j<game->weight-1){
				if(game->grid[i][j]==1){
  				printf("\33[38;2;255;255;255m");
    			printf("|");
    			printf("\33[38;2;255;255;0m");
  				printf("%c",cube(game->grid[i][j]));
				}	
				else if(game->grid[i][j]==2){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;0;255;0m");
					printf("%c",cube(game->grid[i][j]));
				}
				else if(game->grid[i][j]==3){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;0;128m");
					printf("%c",cube(game->grid[i][j]));
				}
				else if(game->grid[i][j]==4){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;0;255;255m");
					printf("%c",cube(game->grid[i][j]));
				}
				else if(game->grid[i][j]==5){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;128;0m");
					printf("%c",cube(game->grid[i][j]));
				}
				else if(game->grid[i][j]==6){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;0;0m");
					printf("%c",cube(game->grid[i][j]));
				}
				else if(game->grid[i][j]==7){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;0;0;255m");
					printf("%c",cube(game->grid[i][j]));
				}	
				else if(game->grid[i][j]==0){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;255;255m");
					printf("%c",cube(game->grid[i][j]));
				}
			}
			
			else{
				if(game->grid[i][j]==1){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;255;0m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}	
				else if(game->grid[i][j]==2){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;0;255;0m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}
				else if(game->grid[i][j]==3){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;0;128m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}
				else if(game->grid[i][j]==4){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;0;255;255m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}
				else if(game->grid[i][j]==5){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;128;0m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}
				else if(game->grid[i][j]==6){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;0;0m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}
				else if(game->grid[i][j]==7){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;0;0;255m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}	
				else if(game->grid[i][j]==0){
					printf("\33[38;2;255;255;255m");
					printf("|");
					printf("\33[38;2;255;255;255m");
					printf("%c",cube(game->grid[i][j]));
					printf("\33[38;2;255;255;255m");
					printf("|");
				}
			}
		}
		 printf("\n");
	}
}
	



void display_grid(game_t* game){//permet d'afficher la grille avec les numéro au dessus et les pièces
	check(game->grid,3);
  printf(" ");
  for(int i=0;i<game->weight;i++){
    printf("%d ",i);
  }
  printf("\n");
  piece_color(game);
}


void show_piece(game_t* game){//permet de montrer à l'utilisateur la pièce qu'il va devoir jouer et ses orientations
  printf("\n");
  if(game->piece.num==0){
    printf("  oo\n  oo\n");
  }
  else if(game->piece.num==1){
    printf("  1     2\n  o  o o o o\n  o\n  o\n  o\n"); 
  }
  else if(game->piece.num==2){
    printf("    1     2\n    o o   o\n  o o     o o\n            o\n"); 
  }
  else if(game->piece.num==3){
  	printf("   1       2\n         o\n o o     o o\n   o o     o\n");
  }
  else if(game->piece.num==4){
    printf("    1     2      3      4\n    o     o    o o o    o\n  o o o   o o    o    o o\n          o             o\n"); 
  }
	else if(game->piece.num==5){
		printf("  1    2       3   4\n  o          o o\n  o    o o o   o   o\n  o o  o       o   o o o\n");
	}
	else if(game->piece.num==6){
		printf("  1     2       3        4\n    o           o o\n    o   o       o    o o o\n  o o   o o o   o        o\n");
	}
	  printf("\n");
}
		



//--------------UPDATE------------------------------------------------


void end(game_t* game){//permet mettre game->end à 1 si une pièce sort de la grille
  for(int i=0;i<4;i++){
    if(game->piece.tab[i].line<4){
      game->end=1;
    }
  }
}

int impossible(game_t* game){//retourne 1 si on ne peut pas jouer la pièce sur cette colonne
  for(int i=0;i<4;i++){
    if(game->piece.tab[i].column<0||game->piece.tab[i].column>game->weight-1){
      printf("Imppossible de choisir cette colonne %i\n",i);
      return 1;
    }
  }
  return 0;
}

int no_orientation(game_t* game){//permet de savoir si l'orientation choisit est valide
	if(game->piece.num==1||game->piece.num==2||game->piece.num==3){
    if(game->piece.orientation==1||game->piece.orientation==2){
      return 1;
    }
    else{
      return 0;
    }
  }
	else if(game->piece.num==4||game->piece.num==5||game->piece.num==6){
		if(game->piece.orientation==1||game->piece.orientation==2||game->piece.orientation==3||game->piece.orientation==4){
      return 1;
		}
    else{
			return 0;
    }
  }  
}

int read_box(int grid[HEIGHT][HEIGHT],int line,int column){//permet de lire une case et de savoir si elle est libre ou non
	if(grid[line][column]==0){
		return 0;
	}
	else{
		return 1;
	}
}


int weight_piece(game_t game){//retourne la largeur de chaque pièce
  if(game.piece.num==0){
    return 2;
  }
  else if(game.piece.num==1){
    if(game.piece.orientation==1){
      return 1;
    }
    else if(game.piece.orientation==2){
      return 4;
    }
  }
  else if(game.piece.num==2||game.piece.num==3){
    if(game.piece.orientation==1){
      return 3;
    }
    else if(game.piece.orientation==2){
      return 2;
    } 
  }
  else if(game.piece.num==4){
    if(game.piece.orientation%2==1){
      return 3;
    }
    else if(game.piece.orientation%2==0){
      return 2;
    }
  }
  else if(game.piece.num==5||game.piece.num==6){
    if(game.piece.orientation%2==1){
      return 2;
    }
    else if(game.piece.orientation%2==0){
      return 3;
    }
  }
}


int height_piece(game_t game){//retourne la hauteur de chaque pièce
  if(game.piece.num==0){
    return 2;
  }
  else if(game.piece.num==1){
    if(game.piece.orientation==1){
      return 4;
    }
    else if(game.piece.orientation==2){
      return 1;
    }
  }
  else if(game.piece.num==2||game.piece.num==3){
    if(game.piece.orientation==1){
      return 2;
    }
    else if(game.piece.orientation==2){
      return 3;
    } 
  }
  else if(game.piece.num==4){
    if(game.piece.orientation%2==1){
      return 2;
    }
    else if(game.piece.orientation%2==0){
      return 3;
    }
  }
  else if(game.piece.num==5||game.piece.num==6){
  	if(game.piece.orientation%2==1){
      return 3;
    }
    else if(game.piece.orientation%2==0){
      return 2;
    }
   }
}

  
int verification(game_t* game){//permet de vérifier que toute les cases utilisés par la pièce sont libres
  int c=0;
  for(int i=0;i<4;i++){
    while(game->grid[game->piece.tab[i].line][game->piece.tab[i].column]==0 && game->piece.tab[0].line<game->height-1 && c<i+1){
      c++;
      if(c==4){
	  		return 1;
      }
    }
    if(game->grid[game->piece.tab[i].line][game->piece.tab[i].column]!=0){
    	if(game->piece.tab[i].line<0){
    		game->end=1;
    	}
    	else{
      game->piece.tab[0].line--;
      create_pieces(game);
      }
      return 0;
    }
  }
}
      
  


void put1(game_t* game){ //permet d'ajouter des 1 dans la grille qui se transformeront en o
	check(game->grid,5);
	for(int k=0;k<7;k++){
		if(game->piece.num==k){
  		for(int i=0;i<4;i++){
    		game->grid[game->piece.tab[i].line][game->piece.tab[i].column]=k+1;
    	}
    }
	}
}








void line_max(game_t* game){//permet de faire les collisions
  game->piece.tab[0].line=height_piece(*game)-1;
  create_pieces(game);
  while(verification(game)!=0){
    game->piece.tab[0].line++;
    create_pieces(game);
  }
}




void placement(game_t* game){//fonction générale du placement de la pièce reprennant toute les fonctions du dessus
	time_t start;
	check(game->grid,5);
  game->piece.num=random_piece();
  printf("\33[38;2;255;255;255m");
  show_piece(game);
  printf("Your score is %d\n\n",game->score);
  start=time(NULL);
  if(game->piece.num!=0){
    do{
      printf("Choose the orientation of the piece:\n\n");
      scanf("%d",&game->piece.orientation);
      flush();
    }while(no_orientation(game)==0);
  }
  do{
   printf("Choose the column:\n");
   game->piece.tab[0].column=-1;
   if(scanf("%d",&(game->piece.tab[0].column))==1){	
		time_t end_column=time(NULL);
		game->timer_to_place=(unsigned long)end_column-start;
		if(game->timer_to_place>15){
		 printf("%lu sec\n",game->timer_to_place);
		 printf("YOU TAKE TOO MUCH TIME\n");
		 game->piece.tab[0].column=rand()%(game->weight-height_piece(*game));
		 printf("The random column choose is %d\n",game->piece.tab[0].column);
		}
		line_max(game);
		create_pieces(game);
		}
  }while(impossible(game));
  end(game);
  	put1(game);
}


int line_full(int **grid,int height,int weight,int line){//permet de savoir si une ligne est pleine
	if(line>=0&&line<height){
		for(int i=0;i<weight;i++){
			if(grid[line][i]==0){
				return 0;
			}
		}
	}	
	return 1;
}


int full(game_t* game){//permet de vérifier toutes les lignes de la grille et de renvoyer celle qui est pleine
	for(int i=0;i<game->height;i++){
		if(line_full(game->grid,game->height,game->weight,i)==1){
			return i;
		}
	}
	return 0;
}





void remove_line(game_t* game){//permet de supprimer une ligne pleine et de faire descendre toutes celle d'au dessus
	check(game->grid,7);
	game->count_full_line=0;
	while((full(game)!=0)){
		game->count_full_line++;
		for(int i=full(game)-1;i>0;i--){
			for(int j=0;j<game->weight;j++){
				game->grid[i+1][j]=game->grid[i][j];
				game->grid[0][j]=0;
			}
		}
	}
	if(game->count_full_line==0){
		game->score=game->score;
	}
	else if(game->count_full_line==1){
		game->score=game->score+10;
	}
	else if(game->count_full_line==2){
		game->score=game->score+40;
	}
	else if(game->count_full_line==3){
		game->score=game->score+100;
	}
	else{
		game->score=game->score+1200;
	}
}

