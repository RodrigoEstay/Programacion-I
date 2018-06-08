#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Fanatico{
	char nombre[100];
	char edad;
	double agresividad;
}Fanatico;

typedef struct Jugador{
	char nombre[100];
	char edad;
	char posicion[20];
	double regate;
	double defensa;
	double velocidad;
	double dureza;
	double resistencia;
}Jugador;

typedef struct Staff{
	char nombre[100];
	char edad;
	char rol[20];
	char experiencia;
}Staff;

typedef struct Equipo{
	char nombre[100];
	int anyoFundacion;
	struct Staff *staff;
	int numStaff[6];
	struct Jugador *jugadores;
	int numJugadores[4];
	struct Fanatico *fanaticos;
	int numFanaticos;
}Equipo;

Fanatico* crearFanaticos(int numFanaticos);

int main(){
	Fanatico *v=crearFanaticos(40);
	int i;
	for(i=0;i<40;++i){
		printf("%d\n", (v+1)->edad);
	}
	return 0;
}

Fanatico* crearFanaticos(int numFanaticos){
	srand(time(NULL));
	Fanatico *fanaticos;
	fanaticos=(Fanatico*)malloc(numFanaticos*sizeof(Fanatico));
	int i;
	for(i=0;i<numFanaticos;++i){
		strcpy((fanaticos+i)->nombre, "SEP");
		(fanaticos+i)->edad=rand()%100;
		(fanaticos+i)->agresividad=(double)rand();
	}
	return fanaticos;
}