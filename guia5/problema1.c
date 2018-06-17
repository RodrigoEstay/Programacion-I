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
	double reflejos;
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
void liberarFanaticos(Fanatico* fans);
Staff* crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc);
void liberarStaff(Staff* staff);
Jugador* crearJugadores(int numArq, int numDef, int numCent, int numDel);
void liberarJugadores(Jugador* jugadores);
Equipo* crearEquipos(int numEquipos);
void liberarEquipos(Equipo* equipos, int numEquipos);
void ordenarDB(Equipo* equipo, int numEquipos);
void imprimiDB(Equipo* equipo, int numEquipos);
char* generarNombre(char *nombre, int seedN, int seedA);

char rNombres[30][15]={"Pedro", "Antonio", "Angela", "Maria", "Jose", "Miguel", "Paula", "Catalina", "Mario", "Andres", 
				"Valentina", "Josefa", "Alexis", "Hugo", "Paola", "Angelica", "Rodrigo", "Ignacio", "Fernanda", "Camila",
				"Cristobal", "Martin", "Ignacia", "Valeria", "Carlos", "Silvana", "Sofia", "Benjamin", "Vicente", "Matias"};
char rApellidos[30][15]={"Gonzales", "Munoz", "Rojas", "Dias", "Perez", "Soto", "Silva", "Contreras", "Lopez", "Rodriguez",
					"Morales", "Martinez", "Fuentes", "Valenzuela", "Araya", "Sepulveda", "Espinoza", "Torres", "Castillo",
					"Reyes", "Freire", "Ruiz", "Pino", "Toro", "Correa", "Medina", "Pinto", "Venegas", "Acevedo", "Salas"};
char rNombreEquipos[20][23]={"Los Leones", "Los Dragones", "Forestal sur", "Bio-Bio FC", "Los Lagartos", "Los Invencibles", 
							"Los Vencedores", "Maipu FC", "Los del Pueblo", "Los Renguinos", "CD Alerce", "Los Imparables",
							"Saturno", "Azukol", "Deportes Rengo", "Master", "Olimpicos", "Los Perfumados", "Condores Negros",
							"Flamencos Endemoniados"};

int main(){
	int numEquipos, maxFanaticos, minFanaticos, numFanaticos, i;
	srand(time(NULL));
	scanf("%d%d%d", &numEquipos, &minFanaticos, &maxFanaticos);
	Equipo* equipo=crearEquipos(numEquipos);
	for(i=0;i<numEquipos;++i){
		numFanaticos=rand()%(maxFanaticos-minFanaticos)+minFanaticos;
		Fanatico* fans=crearFanaticos(numFanaticos);
		Jugador* jug=crearJugadores(3, 6, 7, 6);
		Staff* staff=crearStaff(1, 1, 1, 2, 2, 1);
		equipo[i].staff=staff;
		equipo[i].numStaff[0]=1;
		equipo[i].numStaff[1]=1;
		equipo[i].numStaff[2]=1;
		equipo[i].numStaff[3]=2;
		equipo[i].numStaff[4]=2;
		equipo[i].numStaff[5]=1;
		equipo[i].jugadores=jug;
		equipo[i].numJugadores[0]=3;
		equipo[i].numJugadores[1]=6;
		equipo[i].numJugadores[2]=7;
		equipo[i].numJugadores[3]=6;
		equipo[i].fanaticos=fans;
		equipo[i].numFanaticos=numFanaticos;
	}
	imprimiDB(equipo, numEquipos);
	ordenarDB(equipo, numEquipos);
	imprimiDB(equipo, numEquipos);
	return 0;
}

Fanatico* crearFanaticos(int numFanaticos){
	srand(time(NULL));
	Fanatico *fanaticos;
	fanaticos=(Fanatico*)malloc(numFanaticos*sizeof(Fanatico));
	int i;
	char nombre[100];
	for(i=0;i<numFanaticos;++i){
		generarNombre(nombre, rand()%30, rand()%30);
		strcpy((fanaticos+i)->nombre, nombre);
		(fanaticos+i)->edad=rand()%100;
		(fanaticos+i)->agresividad=(double)rand()/100;
	}
	return fanaticos;
}

void liberarFanaticos(Fanatico* fans){
	free(fans);
}

Staff* crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc){
	int i, total=numDT+numPrepFis+numPrepArq+numAsis+numFisio+numDoc;
	Staff *staff=(Staff*)malloc(total*sizeof(Staff));
	srand(time(NULL));
	char nombre[100];
	for(i=0;i<total;++i){
		if(numDT){
			strcpy((staff+i)->rol, "DT");
			--numDT;
		}
		else if(numPrepArq){
			strcpy((staff+i)->rol, "Preparador Arqueros");
			--numPrepArq;
		}
		else if(numPrepFis){
			strcpy((staff+i)->rol, "Preparador Fisico");
			--numPrepFis;
		}
		else if(numAsis){
			strcpy((staff+i)->rol, "Asistente");
			--numAsis;
		}
		else if(numFisio){
			strcpy((staff+i)->rol, "Fisioterapeuta");
			--numFisio;
		}
		else if(numDoc){
			strcpy((staff+i)->rol, "Doctor");
			--numDoc;
		}
		generarNombre(nombre, rand()%30, rand()%30);
		strcpy((staff+i)->nombre, nombre);
		(staff+i)->edad=rand()%75+20;
		(staff+i)->experiencia=rand()%255;
	}
	return staff;
}

void liberarStaff(Staff* staff){
	free(staff);
}

Jugador* crearJugadores(int numArq, int numDef, int numCent, int numDel){
	int i, total=numArq+numDef+numCent+numDel;
	Jugador *jugadores=(Jugador*)malloc(total*sizeof(Jugador));
	srand(time(NULL));
	char nombre[100];
	for(i=0;i<total;++i){
		if(numArq){
			strcpy((jugadores+i)->posicion, "Arquero");
			--numArq;
		}
		else if(numDef){
			strcpy((jugadores+i)->posicion, "Defensa");
			--numDef;
		}
		else if(numCent){
			strcpy((jugadores+i)->posicion, "Medio");
			--numCent;
		}
		else if(numDel){
			strcpy((jugadores+i)->posicion, "Delantero");
			--numDel;
		}
		generarNombre(nombre, rand()%30, rand()%30);
		strcpy((jugadores+i)->nombre, nombre);
		(jugadores+i)->edad=rand()%13+18;
		(jugadores+i)->regate=(double)rand()/1000000;
		(jugadores+i)->defensa=(double)rand()/1000000;
		(jugadores+i)->reflejos=(double)rand()/1000000;
		(jugadores+i)->velocidad=(double)rand()/1000000;
		(jugadores+i)->dureza=(double)rand()/1000000;
		(jugadores+i)->resistencia=(double)rand()/1000000;
	}
	return jugadores;
}

void liberarJugadores(Jugador* jugadores){
	free(jugadores);
}

Equipo* crearEquipos(int numEquipos){
	Equipo *equipos=(Equipo*)malloc(numEquipos*sizeof(Equipo));
	int i;
	srand(time(NULL));
	for(i=0;i<numEquipos;++i){
		strcpy((equipos+i)->nombre, rNombreEquipos[rand()%19]);
		(equipos+i)->anyoFundacion=1800+rand()%219;
	}
	return equipos;
}

void liberarEquipos(Equipo* equipos, int numEquipos){
	free(equipos);
}

char* generarNombre(char *nombre, int seedN, int seedA){
	char space[2]=" ";
	strcpy(nombre, rNombres[seedN]);
	strcat(nombre, space);
	strcat(nombre, rApellidos[seedA]);
	return nombre;
}

void ordenarDB(Equipo* equipo, int numEquipos){
	int i, j, k, dif, dif2, pos, totalJ, totalS;
	Equipo tempE;
	Jugador tempJ;
	Fanatico tempF;
	Staff tempS;
	for(i=0;i<numEquipos-1;++i){
		for(j=i+1;j<numEquipos;++j){
			dif=strcmp((equipo+i)->nombre, (equipo+j)->nombre);
			if(dif>0){
				tempE=equipo[i];
				equipo[i]=equipo[j];
				equipo[j]=tempE;
			}
		}
	}
	for(i=0;i<numEquipos;++i){
		totalJ=(equipo+i)->numJugadores[0]+(equipo+i)->numJugadores[1]+(equipo+i)->numJugadores[2]+(equipo+i)->numJugadores[3];
		for(j=0;j<totalJ-1;++j){
			for(k=j+1;k<totalJ;++k){
				dif=strcmp(((equipo+i)->jugadores +j)->posicion, ((equipo+i)->jugadores +k)->posicion);
				if(dif>0){
					tempJ=((equipo+i)->jugadores)[j];
					((equipo+i)->jugadores)[j]=((equipo+i)->jugadores)[k];
					((equipo+i)->jugadores)[k]=tempJ;
				}
				else if(dif==0){
					dif2=strcmp(((equipo+i)->jugadores +j)->nombre, ((equipo+i)->jugadores +k)->nombre);
					if(dif2>0){
						tempJ=((equipo+i)->jugadores)[j];
						((equipo+i)->jugadores)[j]=((equipo+i)->jugadores)[k];
						((equipo+i)->jugadores)[k]=tempJ;
					}
				}
			}
		}
		for(j=0;j<(equipo+i)->numFanaticos -1;++j){
			for(k=j+1;k<(equipo+i)->numFanaticos;++k){
				if(((equipo+i)->fanaticos +j)->agresividad > ((equipo+i)->fanaticos +k)->agresividad){
					tempF=((equipo+i)->fanaticos)[j];
					((equipo+i)->fanaticos)[j]=((equipo+i)->fanaticos[k]);
					((equipo+i)->fanaticos)[k]=tempF;
				}
				else if(((equipo+i)->fanaticos +j)->agresividad == ((equipo+i)->fanaticos +k)->agresividad){
					dif=strcmp(((equipo+i)->fanaticos +j)->nombre, ((equipo+i)->fanaticos +j)->nombre);
					if(dif>0){
						tempF=((equipo+i)->fanaticos)[j];
						((equipo+i)->fanaticos)[j]=((equipo+i)->fanaticos)[k];
						((equipo+i)->fanaticos)[k]=tempF;
					}
				}
			}
		}
		totalS=(equipo+i)->numStaff[0]+(equipo+i)->numStaff[1]+(equipo+i)->numStaff[2]+(equipo+i)->numStaff[3]
			+(equipo+i)->numStaff[4]+(equipo+i)->numStaff[5];
		for(j=0;j<totalS-1;++j){
			for(k=j+1;k<totalS;++k){
				dif=strcmp(((equipo+i)->staff +j)->rol, ((equipo+i)->staff +k)->rol);
				if(dif>0){
					tempS=((equipo+i)->staff)[j];
					((equipo+i)->staff)[j]=((equipo+i)->staff)[k];
					((equipo+i)->staff)[k]=tempS;
				}
				else if(dif==0){
					dif2=strcmp(((equipo+i)->staff +j)->nombre, ((equipo+i)->staff +k)->nombre);
					if(dif2>0){
						tempS=((equipo+i)->staff)[j];
						((equipo+i)->staff)[j]=((equipo+i)->staff)[k];
						((equipo+i)->staff)[k]=tempS;
					}
				}
			}
		}
	}
}

void imprimiDB(Equipo* equipo, int numEquipos){
	int i, j, totalS, totalJ;
	for(i=0;i<numEquipos;++i){
		printf("Equipo: %s\nFundado en: %d\n\n", (equipo+i)->nombre, (equipo+i)->anyoFundacion);
		totalJ=(equipo+i)->numJugadores[0]+(equipo+i)->numJugadores[1]+(equipo+i)->numJugadores[2]+(equipo+i)->numJugadores[3];
		printf("Jugadores:\n");
		for(j=0;j<totalJ;++j){
			printf("%20s %3d %9s\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\n", 
				((equipo+i)->jugadores +j)->nombre, ((equipo+i)->jugadores +j)->edad, ((equipo+i)->jugadores +j)->posicion,
				((equipo+i)->jugadores +j)->regate, ((equipo+i)->jugadores +j)->defensa, ((equipo+i)->jugadores +j)->reflejos,
				((equipo+i)->jugadores +j)->velocidad, ((equipo+i)->jugadores +j)->dureza, ((equipo+i)->jugadores +j)->resistencia);
		}
		totalS=(equipo+i)->numStaff[0]+(equipo+i)->numStaff[1]+(equipo+i)->numStaff[2]+(equipo+i)->numStaff[3]
			+(equipo+i)->numStaff[4]+(equipo+i)->numStaff[5];
		printf("\nStaff:\n");
		for(j=0;j<totalS;++j){
			printf("%20s %3d %19s %3d\n", ((equipo+i)->staff +j)->nombre, ((equipo+i)->staff +j)->edad,
				((equipo+i)->staff +j)->rol, ((equipo+i)->staff +j)->experiencia);
		}
		printf("\nFanaticos:\n");
		for(j=0;j<(equipo+i)->numFanaticos;++j){
			printf("%20s %3d %5.3lf\n", ((equipo+i)->fanaticos +j)->nombre, ((equipo+i)->fanaticos +j)->edad,
				((equipo+i)->fanaticos +j)->agresividad);
		}
		if(i<numEquipos-1){
			printf("\n\n");
		}
	}
}