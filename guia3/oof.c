#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main (){
	srand(time(NULL));
	int sr, al=rand()%1500+1000, partidas;
	char ar[100], elo[15];
	printf("Cual es tu cuenta?\n");
	scanf("%s", ar);
	printf("UFF veo que el SR de %s es de %d\nEn que quieres quedar?\n", ar, al);
	scanf("%s", elo);
	if(!strcmp(elo, "Diamante")){
		partidas=(3000-al)/26+rand()%5;
		printf("Ya te jugue %d partidas y gane %d SR y quedaste en Diamante con %d SR. juju\n", partidas, partidas*26, al+partidas*26);
	}
	if(!strcmp(elo, "Maestro")){
		partidas=(3500-al)/26+rand()%5;
		printf("Ya te jugue %d partidas y gane %d SR y quedaste en Maestro con %d SR. juju\n", partidas, partidas*26, al+partidas*26);
	}
	if(!strcmp(elo, "Gran Maestro")){
		partidas=(4000-al)/26+rand()%5;
		printf("Ya te jugue %d partidas y gane %d SR y quedaste en Gran Maestro con %d SR. juju\n", partidas, partidas*26, al+partidas*26);
	}
	if(!strcmp(elo, "Platino")){
		partidas=(2501-al)/26+rand()%5;
		printf("Ya te jugue %d partidas y gane %d SR y quedaste en Platino con %d SR. juju\n", partidas, partidas*26, al+partidas*26);
	}
	if(!strcmp(elo, "Oro")){
		if(al>2000)
			printf("Ya eres oro enfermo.\n");
		else{
			partidas=(2000-al)/26+rand()%5;
			printf("Ya te jugue %d partidas y gane %d SR y quedaste en Oro con %d SR. juju\n", partidas, partidas*26, al+partidas*26);
		}
	}
	return 0;
}