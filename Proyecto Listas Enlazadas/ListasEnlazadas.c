#include <stdlib.h>
#include <stdio.h>

// Falta:	-Poner que se libere las memorias de los punteros de la lista.
//			-Liberar la memoria de los punteros temporales de las funciones.
//			-Una funcion para eliminar un peleador de la lista.
// 			-Que se vea mas bonito cuando se despliegue la lista.
//			-Alguna funcion para editar la informacion de un elemento especifico de la lista
//			(Podria hacerse con algo como ID temporales o algo para identificar los peleadores, 
//			ya que por el nombre no es muy conveniente).
//			-En la funciones de desplegar por categoria de peso y por estilos, yo creo que solo
//			hay que agregar unos cuantos if. Se podrian hacer funciones nuevas o se podria modificar
//			la funcion actual para desplegar la lista.
// 			-Revisar la funcion para agregar elementos, ya que tiene pinta de que algo puede tener malo.

struct peleador{
	char nombre[200];
	double peso;
	int edad;
	double estatura;
	int estilo;
	int ganadas;
	int perdidas;
};

struct nodo{
	struct peleador peleador;
	struct nodo *next;
};

// Declaramos la cabeza y el nodo a analizar de manera global, ya que se ocupan
// por muchas funciones.
struct nodo *head = NULL;
struct nodo *current = NULL;

// Enunciamos las funciones que se encuentran despues del main.
int largo();
void agregar(struct peleador pel);
void desplegarLista();
void leerArchivo();
void guardarArchivo();
void presioneEnterParaContinuar();

int main(){
	leerArchivo();
	int user;
	while(1){// Este while es para que se siga desplegando el menu despues de realizar una accion.
		system("clear");
		printf("Seleccione la operacion a realizar:\n"
			"[1] Agregar peleador.\n"
			"[2] Eliminar peleador.\n"
			"[3] Desplegar toda la lista.\n"
			"[4] Desplegar por categoria de peso.\n"
			"[5] Desplegar por estilos.\n"
			"[6] Editar informacion de estilos.\n"
			"[7] Salir.\n");
		scanf("%d", &user);
		while(user>7 && user<1){ // Validamos la entrada.
			system("clear");
			printf("Opcion invalida, vuelva a seleccionar:\n"
				"[1] Agregar peleador.\n"
				"[2] Eliminar peleador.\n"
				"[3] Desplegar toda la lista.\n"
				"[4] Desplegar por categoria de peso.\n"
				"[5] Desplegar por estilos.\n"
				"[6] Editar informacion de estilos.\n"
				"[7] Salir.\n");
			scanf("%d", &user);
		}
		if(user==1){ // Escaneamos los datos de un peleador, para luego agregarlo a la lista.
			getchar();
			struct peleador pel;
			system("clear");
			printf("Nombre del peleador?\n");
			scanf("%[^\n]", pel.nombre);
			system("clear");
			printf("Edad?\n");
			scanf("%d", &pel.edad);
			system("clear");
			printf("Peso?\n");
			scanf("%lf", &pel.peso);
			system("clear");
			printf("Estatura?\n");
			scanf("%lf", &pel.estatura);
			system("clear");
			printf("Estilo?\n[1] Boxeo.\n[2] Kick Boxing.\n[3] MMA.\n");
			scanf("%d", &pel.estilo);
			system("clear");
			printf("Peleas ganadas?\n");
			scanf("%d", &pel.ganadas);
			system("clear");
			printf("Peleas perdidas?\n");
			scanf("%d", &pel.perdidas);
			agregar(pel);
		}
		else if(user==2){
			
		}
		else if(user==3){ // Simplemente llamamos las funciones correspondientes.
			system("clear");
			desplegarLista();
			presioneEnterParaContinuar();
		}
		else if(user==4){
			
		}
		else if(user==5){
			
		}
		else if(user==6){
			
		}
		else if(user==7){ // Salimos del while para dejar de desplegar el menu.
			system("clear");
			break;
		}
	}
	// Al seleccionarse que se desea salir del programa, guardamos la informacion en un archivo
	// y luego cerramos el programa.
	guardarArchivo();
	return 0;
}

// Calcula cuantos peleadores hay guardados hasta el momento.
int largo(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	current=head;
	int len;
	for(len=0;current!=NULL;++len){
		current=current->next;
	}
	return len;
}

// Se agrega un nuevo peleador de tal manera que se mantenga el orden por peso.
void agregar(struct peleador pel){
	struct nodo *prev=(struct nodo*)malloc(sizeof(struct nodo));
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	struct nodo *temp=(struct nodo*)malloc(sizeof(struct nodo));
	if(temp==NULL || current==NULL){
		printf("ERROR al reservar memoria, intente denuevo.\n");
	}
	current=head;
	printf("SEP\n");
	while(current!=NULL){
		if(current->peleador.peso>pel.peso){
			break;
		}
		prev=current;
		current=current->next;
	}
	temp->peleador=pel;
	if(current==head){
		temp->next=head;
		head=temp;
	}
	else{
		temp->next=current;
		prev->next=temp;
	}
}

// Se despliega la lista, los if son para traducir desde entero a palabra el estilo del peleador.
void desplegarLista(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	if(current==NULL){
		printf("ERROR al reservar memoria.\n");
	}
	current=head;
	int i=1;
	while(current!=NULL){
		printf("%d %s\t%d\t%.2lf\t%.2lf\t", i, current->peleador.nombre, current->peleador.edad, current->peleador.peso,
			current->peleador.estatura);
		if(current->peleador.estilo==1){
			printf("Boxeo\t");
		}
		else if(current->peleador.estilo==2){
			printf("Kick Boxing\t");
		}
		else if(current->peleador.estilo==3){
			printf("MMA\t");
		}
		printf("%d\t%d\n", current->peleador.ganadas, current->peleador.perdidas);
		current=current->next;
		++i;
	}
}

// Esta funcion lee un archivo de una manera especifica, la cual es igual a la manera en la que se guarda.
void leerArchivo(){
	FILE *archivo=NULL;
	archivo=fopen("datos.txt", "r");
	if(archivo!=NULL){
		int num;
		char saltoDeLinea;
		struct peleador pel;
		fscanf(archivo, "%d", &num);
		printf("%d\n", num);
		if(num==0){
			return;
		}
		while(num--){
			fscanf(archivo, "%c", &saltoDeLinea);
			fscanf(archivo, "%[^\n] %lf %d %lf %d %d %d", pel.nombre, &pel.peso, &pel.edad, &pel.estatura, &pel.estilo,
				&pel.ganadas, &pel.perdidas);
			agregar(pel);
		}
	}
	fclose(archivo);
}

// Se guarda en el archivo los datos de manera ordenada (Por el peso).
void guardarArchivo(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	FILE *archivo=NULL;
	archivo=fopen("datos.txt", "w");
	if(current==NULL){
		printf("ERROR al reservar memoria.\n");
	}
	int n=largo();
	fprintf(archivo, "%d\n", n);
	current=head;
	while(current!=NULL){
		fprintf(archivo, "%s\n%.2lf %d %.2lf %d %d %d\n", current->peleador.nombre, current->peleador.peso, current->peleador.edad, 
			current->peleador.estatura, current->peleador.estilo, current->peleador.ganadas, current->peleador.perdidas);
		current=current->next;
	}
	fclose(archivo);
}

// Se ocupa para que algunos mensajes no desaparezcan.
void presioneEnterParaContinuar(){
	printf("\nPresione Enter para continuar...\n");
	getchar();
	getchar();
}