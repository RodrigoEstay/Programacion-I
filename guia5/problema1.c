#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Programa hecho sin ayuda.

// Definimos las estructuras como se nos pidio:
typedef struct Fanatico{
	char nombre[100];
	unsigned char edad;
	double agresividad;
}Fanatico;

typedef struct Jugador{
	char nombre[100];
	unsigned char edad;
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
	unsigned char edad;
	char rol[20];
	unsigned char experiencia;
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

// Estas variables globales son para definir nombres aleatorios de tanto personas como equipos.

char rNombres[30][15]={"Pedro", "Antonio", "Angela", "Maria", "Jose", "Miguel", "Paula",
				"Catalina", "Mario", "Andres", "Valentina", "Josefa", "Alexis", "Hugo",
				"Paola", "Angelica", "Rodrigo", "Ignacio", "Fernanda", "Camila","Cristobal",
				"Martin", "Ignacia", "Valeria", "Carlos", "Silvana", "Sofia", "Benjamin",
				"Vicente", "Matias"};
char rApellidos[30][15]={"Gonzales", "Munoz", "Rojas", "Dias", "Perez", "Soto", "Silva",
				"Contreras", "Lopez", "Rodriguez","Morales", "Martinez", "Fuentes", "Estay",
				"Araya", "Sepulveda", "Espinoza", "Torres", "Castillo","Reyes", "Freire",
				"Ruiz", "Pino", "Toro", "Correa", "Medina", "Pinto", "Venegas", "Acevedo", "Salas"};
char rNombreEquipos[20][23]={"Los Leones", "Los Dragones", "Forestal sur", "Bio-Bio FC", "Los Lagartos",
				"Los Invencibles", "Los Vencedores", "Maipu FC", "Los del Pueblo", "Los Renguinos",
				"CD Alerce", "Los Imparables","Saturno", "Azukol", "Deportes Rengo", "Master",
				"Olimpicos", "Los Perfumados", "Condores Negros","Flamencos Endemoniados"};

int main(){
	system("clear");
	int numEquipos, maxFanaticos, minFanaticos, numFanaticos, i;
	// Decalaramos srand esta unica vez para generar todos los casos aleatorios.
	srand(time(NULL));
	printf("Ingrese el numero de equipos y el numero minimo y maximo de fanaticos.\n");
	scanf("%d%d%d", &numEquipos, &minFanaticos, &maxFanaticos);
	Equipo* equipo=crearEquipos(numEquipos);
	// Para cada equipo le asignamos un numero aleatorio de fanaticos con los limites ingresados,
	// creamos el numero de staff y jugadores indicados, luego al equipo le asignamos el numero
	// de jugadores  y de staff de cada tipo que va a tener y de fans, luego le asignamos los punteros
	// generados al principio.
	for(i=0;i<numEquipos;++i){
		numFanaticos=rand()%(maxFanaticos-minFanaticos+1)+minFanaticos;
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
	// LLamamos las funciones.
	system("clear");
	imprimiDB(equipo, numEquipos);
	printf("\nPresione Enter para ordenar la lista\n");
	getchar();
	getchar();
	system("clear");
	ordenarDB(equipo, numEquipos);
	imprimiDB(equipo, numEquipos);
	// Liberamos la memoria.
	liberarEquipos(equipo, numEquipos);
	return 0;
}

// En esta funcion solo se generan los valores aleatoriamente y se lo asignamos a los fanaticos.
// La funcion generarNombre devuelve un nombre y apellido aleatorio.
Fanatico* crearFanaticos(int numFanaticos){
	Fanatico *fanaticos;
	fanaticos=(Fanatico*)malloc(numFanaticos*sizeof(Fanatico));
	int i;
	char nombre[100];
	for(i=0;i<numFanaticos;++i){
		generarNombre(nombre, rand()%30, rand()%30);
		strcpy((fanaticos+i)->nombre, nombre);
		(fanaticos+i)->edad=rand()%100+1; // Edad desde 1-100.
		(fanaticos+i)->agresividad=(double)rand()/100;
	}
	return fanaticos;
}

// Se libera su memoria.
void liberarFanaticos(Fanatico* fans){
	free(fans);
}

// Creamos los miembros del staff con la cantidad de roles especificada, y luego le asignamos valores
// aleatrios de una manera parecida que a los fanaticos.
Staff* crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc){
	int i, total=numDT+numPrepFis+numPrepArq+numAsis+numFisio+numDoc;
	Staff *staff=(Staff*)malloc(total*sizeof(Staff));
	char nombre[100];
	// En este ciclo se le va asignando el rol a cada miembro del staff creado, observamos
	// que por cada vez que se crea el staff se ejecuta un if y luego se disminuye su numero,
	// de esta manera cuando el numero llegue a 0 se dejaran de crear staff con ese rol.
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
		(staff+i)->edad=rand()%75+20; // Edad desde 20-74.
		(staff+i)->experiencia=rand()%256;
	}
	return staff;
}

// Liberamos la memoria del staff.
void liberarStaff(Staff* staff){
	free(staff);
}

// Se crean numeros aleatorios para los distintos valores de los jugadores, y si le generan
// nombres, la cantidad de jugadores creados para cada posicion es igual a como se hizo
// en el staff. Cabe notar que los valores generados aleatoriamente para los de coma flotante
// de precision doble son divididos por numeros muy altos, es para evitar que estos valores
// sean muy grandes, ya que asi despues no se pueden imprimir ordenadamente.
Jugador* crearJugadores(int numArq, int numDef, int numCent, int numDel){
	int i, total=numArq+numDef+numCent+numDel;
	Jugador *jugadores=(Jugador*)malloc(total*sizeof(Jugador));
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
		(jugadores+i)->edad=rand()%13+18; // Edad desde 18-30.
		(jugadores+i)->regate=(double)rand()/10000000;
		(jugadores+i)->defensa=(double)rand()/1000000;
		(jugadores+i)->reflejos=(double)rand()/1000000;
		(jugadores+i)->velocidad=(double)rand()/1000000;
		(jugadores+i)->dureza=(double)rand()/1000000;
		(jugadores+i)->resistencia=(double)rand()/1000000;
	}
	return jugadores;
}

// Se libera la memoria de los jugadores.
void liberarJugadores(Jugador* jugadores){
	free(jugadores);
}

// Se crean los equipos con nombres aleatorios.
Equipo* crearEquipos(int numEquipos){
	Equipo *equipos=(Equipo*)malloc(numEquipos*sizeof(Equipo));
	int i, j;
	for(i=0;i<numEquipos;++i){
		strcpy((equipos+i)->nombre, rNombreEquipos[rand()%20]);
		// Para los primeros 20 equipos nos aseguramos de que sus nombres sean distintos.
		// Solo nos preocupamos de los primeros 20 porque nuestra variable global con
		// nombres para los equipos solo tiene 20 nombres posibles, asi que pasados
		// los 20 nombres generados, se pueden empezar a repetir.
		if(i<20){
			for(j=0;j<i;++j){
				if(!strcmp((equipos+j)->nombre, (equipos+i)->nombre)){
					strcpy((equipos+i)->nombre, rNombreEquipos[rand()%19]);
					j=-1;
				}
			}
		}
		// Año de fundacion desde 1800-2018.
		(equipos+i)->anyoFundacion=1800+rand()%219;
	}
	return equipos;
}

// Para cada equipo liberamos la memoria de todos sus vectores, y luego la de los equipos.
void liberarEquipos(Equipo* equipos, int numEquipos){
	int i;
	for(i=0;i<numEquipos;++i){
		liberarFanaticos((equipos+i)->fanaticos);
		liberarJugadores((equipos+i)->jugadores);
		liberarStaff((equipos+i)->staff);
	}
	free(equipos);
}

// Esta funcion recibe un string y dos valores, y modifica este string para que sea
// un nombre aleatorio, donde el nombre es generado a partir del primer valor, y el
// apellido es generado a partir del segundo valor.
char* generarNombre(char *nombre, int seedN, int seedA){
	char space[2]=" ";
	strcpy(nombre, rNombres[seedN]);
	strcat(nombre, space);
	strcat(nombre, rApellidos[seedA]);
	return nombre;
}

// Funcion que ordena segun los criterios especificados
void ordenarDB(Equipo* equipo, int numEquipos){
	int i, j, k, dif, dif2, pos, totalJ, totalS;
	// Valores temporales para cada estructura para ordenarlos como se especifico.
	Equipo tempE;
	Jugador tempJ;
	Fanatico tempF;
	Staff tempS;
	// Este ciclo ordena los nombres de los equipos en orden alfabetico ascendente.
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
	// Una vez ordenados los equipos comenzamos a ordenar los distintos vectores que posee.
	for(i=0;i<numEquipos;++i){
		// Calculamos numero total de jugadores.
		totalJ=(equipo+i)->numJugadores[0]+(equipo+i)->numJugadores[1]+(equipo+i)->numJugadores[2]
				+(equipo+i)->numJugadores[3];
		// En este ciclo se ordenan los jugadores, primero por posicion en orden alfabetico.
		for(j=0;j<totalJ-1;++j){
			for(k=j+1;k<totalJ;++k){
				dif=strcmp(((equipo+i)->jugadores +j)->posicion, ((equipo+i)->jugadores +k)->posicion);
				if(dif>0){
					tempJ=((equipo+i)->jugadores)[j];
					((equipo+i)->jugadores)[j]=((equipo+i)->jugadores)[k];
					((equipo+i)->jugadores)[k]=tempJ;
				}
				else if(dif==0){ // Si poseen la misma posicion, se ordena por nombre.
					dif2=strcmp(((equipo+i)->jugadores +j)->nombre, ((equipo+i)->jugadores +k)->nombre);
					if(dif2>0){
						tempJ=((equipo+i)->jugadores)[j];
						((equipo+i)->jugadores)[j]=((equipo+i)->jugadores)[k];
						((equipo+i)->jugadores)[k]=tempJ;
					}
				}
			}
		}
		// Este ciclo ordena los fanaticos por agresividad (ascendentemente).
		for(j=0;j<(equipo+i)->numFanaticos -1;++j){
			for(k=j+1;k<(equipo+i)->numFanaticos;++k){
				if(((equipo+i)->fanaticos +j)->agresividad > ((equipo+i)->fanaticos +k)->agresividad){
					tempF=((equipo+i)->fanaticos)[j];
					((equipo+i)->fanaticos)[j]=((equipo+i)->fanaticos[k]);
					((equipo+i)->fanaticos)[k]=tempF;
				}
				// Si poseen el mismo valor de agresividad, se ordenan por nombre.
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
		// Calculamos el numero total de staff.
		totalS=(equipo+i)->numStaff[0]+(equipo+i)->numStaff[1]+(equipo+i)->numStaff[2]+(equipo+i)->numStaff[3]
			+(equipo+i)->numStaff[4]+(equipo+i)->numStaff[5];
		// Este ciclo ordena el staff por su rol (alfabeticamente).
		for(j=0;j<totalS-1;++j){
			for(k=j+1;k<totalS;++k){
				dif=strcmp(((equipo+i)->staff +j)->rol, ((equipo+i)->staff +k)->rol);
				if(dif>0){
					tempS=((equipo+i)->staff)[j];
					((equipo+i)->staff)[j]=((equipo+i)->staff)[k];
					((equipo+i)->staff)[k]=tempS;
				}
				else if(dif==0){ // Si poseen el mismo rol, se ordena por nombre.
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

// Esta funcion simplemente imprime los datos de la manera mas ordenada posible.
void imprimiDB(Equipo* equipo, int numEquipos){
	int i, j, totalS, totalJ;
	for(i=0;i<numEquipos;++i){
		printf("Equipo: %s\nFundado en: %d\n\n", (equipo+i)->nombre, (equipo+i)->anyoFundacion);
		// Calculamos total de juadores.
		totalJ=(equipo+i)->numJugadores[0]+(equipo+i)->numJugadores[1]+(equipo+i)->numJugadores[2]
				+(equipo+i)->numJugadores[3];
		printf("Jugadores:\n");
		// Los espacios en blanco son considerando los espacios que tomaran los string.
		printf("        Nombre     Edad Posicion Regate\tDefensa\tReflej\tVelo\tDureza\tResisten\n");
		for(j=0;j<totalJ;++j){
			// Hacemos que siempre ocupen una cantidad de espacios en blancos para mantener el orden.
			printf("%19s %2u %9s %5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\n", 
				((equipo+i)->jugadores +j)->nombre, ((equipo+i)->jugadores +j)->edad,
				((equipo+i)->jugadores +j)->posicion, ((equipo+i)->jugadores +j)->regate,
				((equipo+i)->jugadores +j)->defensa, ((equipo+i)->jugadores +j)->reflejos,
				((equipo+i)->jugadores +j)->velocidad, ((equipo+i)->jugadores +j)->dureza,
				((equipo+i)->jugadores +j)->resistencia);
		}
		// Calculamos el numero total de staff y se imprimen de manera parecida que los jugadores.
		totalS=(equipo+i)->numStaff[0]+(equipo+i)->numStaff[1]+(equipo+i)->numStaff[2]+(equipo+i)->numStaff[3]
			+(equipo+i)->numStaff[4]+(equipo+i)->numStaff[5];
		printf("\nStaff:\n");
		printf("        Nombre     Edad         Rol         Experiencia\n");
		for(j=0;j<totalS;++j){
			printf("%19s %3u %19s %3u\n", ((equipo+i)->staff +j)->nombre, ((equipo+i)->staff +j)->edad,
				((equipo+i)->staff +j)->rol, ((equipo+i)->staff +j)->experiencia);
		}
		printf("\nFanaticos:\n");
		printf("        Nombre     Edad Agresividad\n");
		for(j=0;j<(equipo+i)->numFanaticos;++j){
			printf("%19s %3u %5.3lf\n", ((equipo+i)->fanaticos +j)->nombre, ((equipo+i)->fanaticos +j)->edad,
				((equipo+i)->fanaticos +j)->agresividad);
		}
		// Imprimimos dos saltos de linea a no ser que se trate del ultimo equipo impreso.
		if(i<numEquipos-1){
			printf("\n\n");
		}
	}
}