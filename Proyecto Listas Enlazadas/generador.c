#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char* generarNombre(char *nombre);

char nombres[40][100]={"BENJAMIN", "VICENTE", "MARTIN", "MATIAS", "JOAQUIN", "AGUSTIN", "CRISTOBAL", "MAXIMILIANO", "SEBASTIAN", "FELIPE"
						, "TOMAS", "DIEGO", "JOSE", "NICOLAS", "LUCAS", "ALONSO", "BASTIAN", "JUAN", "GABRIEL", "IGNACIO"
						, "FRANCISCO", "RENATO", "MAXIMO", "MATEO", "JAVIER", "DANIEL", "LUIS", "GASPAR", "ANGEL", "FERNANDO"
						, "CARLOS", "EMILIO", "FRANCO", "CRISTIAN", "PABLO", "SANTIAGO", "ESTEBAN", "DAVID", "DAMIAN", "JORGE"};
char apellidos[30][100]={"GONZALEZ", "MUNOZ", "ROJAS", "DIAZ", "PEREZ", "SOTO", "SILVA", "CONTRERAS", "LOPEZ", "RODRIGUEZ"
						, "MORALES", "MARTINEZ", "FUENTES", "VALENZUELA", "ARAYA", "SEPULVEDA", "ESPINOZA", "TORRES", "CASTILLO", "REYES"
						, "RAMIREZ", "FLORES", "CASTRO", "FERNANDEZ", "ALVAREZ", "HERNANDEZ", "HERRERA", "VARGAS", "GUITARREZ", "GOMEZ"};

int main(){
	FILE *archivo=NULL;
	archivo=fopen("datoss.txt", "w");
	int cant;
	char nombre[100];
	scanf("%d", &cant);
	srand(time(NULL));
	fprintf(archivo, "%d\n", cant);
	while(cant--){
		fprintf(archivo, "%s\n%.2lf %d %.2lf %d %d %d\n", generarNombre(nombre), 62.0+(rand()%101)/2.57, 16+rand()%15, 1.50+(rand()%101)/179.9,
			1+rand()%3, rand()%15, rand()%15);
	}
	fclose(archivo);
	return 0;
}

char* generarNombre(char *nombre){
	char espacio[2]=" ";
	strcpy(nombre, nombres[rand()%41]);
	strcat(nombre, espacio);
	strcat(nombre, apellidos[rand()%31]);
	return nombre;
}