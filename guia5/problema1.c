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
char* generarNombre(char *nombre, int seedN, int seedA);
void ordenarDB(Equipo* equipo);

char rNombres[30][15]={"Pedro", "Antonio", "Angela", "Maria", "Jose", "Miguel", "Paula", "Catalina", "Mario", "Andres", 
				"Valentina", "Josefa", "Alexis", "Hugo", "Paola", "Angelica", "Rodrigo", "Ignacio", "Fernanda", "Camila",
				"Cristobal", "Martin", "Ignacia", "Valeria", "Carlos", "Silvana", "Sofia", "Benjamin", "Vicente", "Matias"};
char rApellidos[30][15]={"Gonzales", "Muñoz", "Rojas", "Dias", "Perez", "Soto", "Silva", "Contreras", "Lopez", "Rodriguez",
					"Morales", "Martinez", "Fuentes", "Valenzuela", "Araya", "Sepulveda", "Espinoza", "Torres", "Castillo",
					"Reyes", "Freire", "Ruiz", "Pino", "Toro", "Correa", "Medina", "Pinto", "Venegas", "Acevedo", "Salas"};
char rNombreEquipos[20][23]={"Los Leones", "Los Dragones", "Forestal sur", "Bio-Bio FC" "Los Lagartos", "Los Invencibles", 
							"Los Vencedores", "Maipu FC" "Los del Pueblo", "Los Renguinos", "CD Alerce" "Los Imparables",
							"Saturno", "Azukol", "Deportes Rengo", "Master", "Olimpicos", "Los Perfumados", "Condores Negros",
							"Flamencos Endemoniados"};

int main(){
	Fanatico *v=crearFanaticos(40);
	int i;
	for(i=0;i<40;++i){
		printf("%s %d %lf\n",(v+i)->nombre, (v+i)->edad,(v+i)->agresividad);
	}
	char a[2][7]={"hola", "chao"};
	printf("%s %s\n", a[0], a[1]);
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
		(jugadores+i)->regate=(double)rand()/10000;
		(jugadores+i)->defensa=(double)rand()/10000;
		(jugadores+i)->reflejos=(double)rand()/10000;
		(jugadores+i)->velocidad=(double)rand()/10000;
		(jugadores+i)->dureza=(double)rand()/10000;
		(jugadores+i)->resistencia=(double)rand()/10000;
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

void ordenarDB(Equipo* equipo){
	int i, j, k, pos, total=0;
	Staff tempS;
	char StaffRoles[6][25]={"DT", "Preparador Arqueros", "Preparador Fisico", "Asistente", "Fisioterapeuta", "Doctor"};
	for(i=0, pos=0;i<6;++i){
		for(j=pos;j<equipo->numStaff[i];++j){
			if(!strcmp((equipo->staff+pos+j)->rol, StaffRoles[i])){
				tempS=*(equipo->staff+pos+j);
				*(equipo->staff+pos+j)=*(equipo->staff+pos);
				*(equipo->staff+pos)=tempS;
				++pos;
			}
		}
		for(k=pos-equipo->numStaff[i];k<pos-1;++k){
			for(j=k+1;j<equipo->numStaff[i];++j){
				char t=strcmp(equipo->((staff+k)->nombre), equipo->((staff+j)->nombre));
				if(t>0){
					tempS=equipo->(staff+j);
					equipo->(staff+j)=equipo->(staff+k);
					equipo->(staff+k)=tempS;
				}
			}
		}
		total+=equipo->numStaff[i];
	}
	
}