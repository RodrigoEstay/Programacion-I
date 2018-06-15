#include <stdlib.h>
#include <stdio.h>

// Falta:	-Poner que se libere las memorias de los punteros de la lista.
//			-Liberar la memoria de los punteros temporales de las funciones.
// 			-Que se vea mas bonito cuando se despliegue la lista.
//			-En la funciones de desplegar por categoria de peso y por estilos, yo creo que solo
//			hay que agregar unos cuantos if. Se podrian hacer funciones nuevas o se podria modificar
//			la funcion actual para desplegar la lista.
//			-Validar entrada para los estilos.

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
void eliminar(int id);
void modificar(int id);
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
			"[6] Editar informacion de peleadores.\n"
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
				"[6] Editar informacion de peleadores.\n"
				"[7] Salir.\n");
			scanf("%d", &user);
		}
		if(user==1){ // Escaneamos los datos de un peleador, para luego agregarlo a la lista.
			getchar();
			struct peleador pel;
			system("clear");
			printf("Nombre del peleador:\n");
			scanf("%[^\n]", pel.nombre);
			system("clear");
			printf("Edad:\n");
			scanf("%d", &pel.edad);
			system("clear");
			printf("Peso:\n");
			scanf("%lf", &pel.peso);
			system("clear");
			printf("Estatura:\n");
			scanf("%lf", &pel.estatura);
			system("clear");
			printf("Estilo:\n[1] Boxeo.\n[2] Kick Boxing.\n[3] MMA.\n");
			scanf("%d", &pel.estilo);
			system("clear");
			printf("Peleas ganadas:\n");
			scanf("%d", &pel.ganadas);
			system("clear");
			printf("Peleas perdidas:\n");
			scanf("%d", &pel.perdidas);
			agregar(pel);
		}
		else if(user==2){
			system("clear");
			if(largo()==0){
				printf("No existen peleadores.\n");
				presioneEnterParaContinuar();
				continue;
			}
			desplegarLista();
			printf("\nIngrese ID a eliminar o [0] para volver al menu:\n");
			int ID;
			scanf("%d", &ID);
			while(ID<0 || largo()<ID){
				printf("Entrada invalida, ingrese nuevamente:\n");
				scanf("%d", &ID);
			}
			if(ID==0){
				continue;
			}
			eliminar(ID);
			printf("Eliminado\n");
			presioneEnterParaContinuar();
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
			system("clear");
			if(largo()==0){
				printf("No existen peleadores.\n");
				presioneEnterParaContinuar();
				continue;
			}
			desplegarLista();
			printf("\nIngrese ID a modificar o [0] para volver al menu:\n");
			int ID;
			scanf("%d", &ID);
			while(ID<0 || largo()<ID){
				printf("Entrada invalida, ingrese nuevamente:\n");
				scanf("%d", &ID);
			}
			if(ID==0){
				continue;
			}
			modificar(ID);
			system("clear");
			printf("Datos modificados\n");
			presioneEnterParaContinuar();
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
		printf("%3d %20s %d\t%.2lf\t%.2lf\t", i, current->peleador.nombre, current->peleador.edad, current->peleador.peso,
			current->peleador.estatura);
		if(current->peleador.estilo==1){
			printf("Boxeo       ");
		}
		else if(current->peleador.estilo==2){
			printf("Kick Boxing ");
		}
		else if(current->peleador.estilo==3){
			printf("MMA         ");
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
	printf("hola\n");
	if(archivo!=NULL){
		printf("chao\n");
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
		fclose(archivo);
	}
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

// Elimina un peleador especifico de la lista desplegada (Por ID).
void eliminar(int id){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	struct nodo *prev=(struct nodo*)malloc(sizeof(struct nodo));
	current=head;
	--id;
	while(current!=NULL && id){
		prev=current;
		current=current->next;
		--id;
	}
	if(current==head){
		head=head->next;
		free(current);
	}
	prev->next=current->next;
}

void modificar(int id){
	int ID=id;
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	int entrada;
	current=head;
	--id;
	while(current!=NULL && id){
		current=current->next;
		--id;
	}
	system("clear");
	printf("%3d %20s %d\t%.2lf\t%.2lf\t", ID, current->peleador.nombre, current->peleador.edad, current->peleador.peso,
			current->peleador.estatura);
		if(current->peleador.estilo==1){
			printf("Boxeo       ");
		}
		else if(current->peleador.estilo==2){
			printf("Kick Boxing ");
		}
		else if(current->peleador.estilo==3){
			printf("MMA         ");
		}
		printf("%d\t%d\n\n", current->peleador.ganadas, current->peleador.perdidas);
	printf("Que desea modificar:\n"
			"[1] Nombre.\n"
			"[2] Edad\n"
			"[3] Peso.\n"
			"[4] Estatura.\n"
			"[5] Estilo.\n"
			"[6] Peleas ganadas.\n"
			"[7] Peleas perdidas.\n"
			"[0] Volver al menu\n");
	scanf("%d", &entrada);
	while(entrada>7 || entrada<0){
		printf("Entrada invalida, ingrese nuevamente:\n");
		scanf("%d", &entrada);
	}
	getchar();
	fflush(stdin);
	system("clear");
	if(entrada==0){
		return;
	}
	if(entrada==1){
		printf("Nombre anterior: %s\nIngrese nuevo nombre:\n", current->peleador.nombre);
		scanf("%[^\n]", current->peleador.nombre);
	}
	else if(entrada==2){
		printf("Edad anterior: %d\nIngrese nueva edad:\n", current->peleador.edad);
		scanf("%d", &(current->peleador.edad));
	}
	else if(entrada==3){
		printf("Peso anterior: %lf\nIngrese nuevo peso:\n", current->peleador.peso);
		scanf("%lf", &(current->peleador.peso));
	}
	else if(entrada==4){
		printf("Estatura anterior: %lf\nIngrese nueva estatura.\n", current->peleador.estatura);
		scanf("%lf", &(current->peleador.estatura));
	}
	else if(entrada==5){
		printf("Estilo anterior: ");
		if(current->peleador.estilo==1){
			printf("Boxeo\n");
		}
		else if(current->peleador.estilo==2){
			printf("Kick Boxing\n");
		}
		else if(current->peleador.estilo==3){
			printf("MMA\n");
		}
		int temp;
		printf("Ingrese nuevo estilo:\n[1] Boxeo.\n[2] Kick Boxing.\n[3] MMA.\n");
		scanf("%d", &temp);
		while(temp>3 || temp<1){
			printf("Entrada invalida, ingrese nuevamente:\n");
			scanf("%d", &temp);
		}
		current->peleador.estilo=temp;
	}
	else if(entrada==6){
		printf("Peleas ganadas: %d\nIngrese nueva cantidad.\n", current->peleador.ganadas);
		scanf("%d", &(current->peleador.ganadas));
	}
	else if(entrada==7){
		printf("Peleas perdidas: %d\nIngrese nueva cantidad.\n", current->peleador.perdidas);
		scanf("%d", &(current->peleador.perdidas));
	}
}

// Se ocupa para que algunos mensajes no desaparezcan.
void presioneEnterParaContinuar(){
	printf("\nPresione Enter para continuar...\n");
	getchar();
	getchar();
}