#include <stdlib.h>
#include <stdio.h>

// Proyecto Linked List

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

// Declaramos la cabeza de manera global, ya que se ocupa por muchas funciones.

struct nodo *head = NULL;

// Enunciamos las funciones que se encuentran despues del main.

void imprimirPeleador(struct peleador pel, int i);
int largo();
void agregar(struct peleador pel);
void desplegarLista();
void leerArchivo();
void guardarArchivo();
void eliminar(int id);
int modificar(int id);
void desplegarPorEstilos(int estilo);
void desplegarPorPesos(int catPeso);
void liberarMemoria();
void presioneEnterParaContinuar();

int main(){

	// 	Leemos el archivo, agregando los datos manteniendo el orden, es decir, se pueden
	// leer datos de manera desordenada, y se agregaran de manera que la lista este ordenada.

	leerArchivo();

	// 	Este while es para que se siga desplegando el menu despues de realizar una accion.

	int user;
	while(1){

		// 	Le pedimos al usuario que elija una accion a reliazar, lo hacemos a traves de numeros
		// que identifican cada accion, luego se valida la entrada por si ingresa una opcion no
		// existente.

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

		// Accion 1, agregar un peleador a la lista:
		// 	Primero le pedimos al usuario que ingrese toos los datos de un peleador, los cuales se
		// almacenan en una estructura tipo peleador, la cual luego se envia a la funcion respectiva
		// para añadir el peleador a la lista en su posicion correcta.

		if(user==1){
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
			while(pel.estilo<1 || pel.estilo>3){
				printf("Entrada invalida, Reingrese valor.\n");
				printf("Estilo:\n[1] Boxeo.\n[2] Kick Boxing.\n[3] MMA.\n");
				scanf("%d", &pel.estilo);
			}
			system("clear");
			printf("Peleas ganadas:\n");
			scanf("%d", &pel.ganadas);
			system("clear");
			printf("Peleas perdidas:\n");
			scanf("%d", &pel.perdidas);
			agregar(pel);
		}

		// Accion 2, elimninar un peleador de la lista:
		// 	Primero revisamos si es que existen peleadores, si es que hay, desplegamos la lista completa
		// asignandole una ID a cada peleador, el cual corresponde a su posicion en la lista, luego le
		// pedimos al usuario que ingrese el ID del peleador a eliminar, luego mandamos la ID a la funcion
		// eliminar que avanza hasta la posicion deseada y elimina el elemento.

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

		// Accion 3, desplegar la lista completa:
		// 	Si es que hay peleadores, se llama a la funcion desplegar lista, sino, se informa
		// que no hay peleadores.

		else if(user==3){
			system("clear");
			if(!largo()){
				printf("No existen peleadores...\n");
			}
			else{
				desplegarLista();
			}
			presioneEnterParaContinuar();
		}

		// Accion 4, desplegar por categoria de peso:
		// 	Nuevamente revisamos la existencia de peleadores, y luego le pedimos al usuario que elija una categoria
		// de peso, validando la entrada, y luego desplegamos a los peleadores en esa categoria de peso.

		else if(user==4){
			system("clear");
			if(!largo()){
				printf("No existen peleadores...\n");
			}
			else{
				printf("Ingrese categoria de peso:\n[1] Peso ligero.\n[2] Peso welter.\n[3] Peso medio.\n[4] Peso semipesado.\n[5] Peso pesado.\n");
				int PESO;
				scanf("%d", &PESO);
				while(PESO<1 || PESO>5){
					system("clear");
					printf("Entrada invalida.\nIngrese categoria de peso:\n[1] Peso ligero.\n[2] Peso welter.\n [3] Peso medio.\n [4] Peso semipesado.\n [5] Peso pesado.\n\n");
					scanf("%d", &PESO);
				}
				system("clear");
				desplegarPorPesos(PESO);
			}
			presioneEnterParaContinuar();
		}

		// Accion 5, deplegar por estilo:
		// 	Revisamos la existencia de los peleadores, luego el usuario ingresa el estilo a desplegar, validamos
		// la entrada, y desplegamos los peleadores que conocen ese estilo de pelea.  

		else if(user==5){
			system("clear");
			if(!largo()){
				printf("No existen peleadores...\n");
			}
			else{
				printf("Ingrese el estilo a desplegar:\n[1] Boxeo.\n[2] Kick Boxing.\n[3] MMA.\n");
				int ID;
				scanf("%d", &ID);
				while(ID<1 || ID>3){
					system("clear");
					printf("Entrada invalida.\nIngrese el estilo a desplegar:\n[1] Boxeo.\n[2] Kick Boxing.\n[3] MMA.\n");
					scanf("%d", &ID);
				}
				system("clear");
				desplegarPorEstilos(ID);
			}
			presioneEnterParaContinuar();
		}

		// Accion 6, modificar peleador:
		// 	Si es que hay peleadores, le desplegamos la lista al usuario y le pedimos que ingrese
		// el ID del peleador a modificar.

		else if(user==6){
			system("clear");
			if(!largo()){
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
			if(modificar(ID)){
				continue;
			}
			system("clear");
			printf("Datos modificados\n");
			presioneEnterParaContinuar();
		}

		// Accion 7, salir del programa.

		else if(user==7){
			break;
		}
	}
	
	// 	Cuando se sale del programa, se guardan los datos en datos.txt, y luego se libera
	// la memoria.

	system("clear");
	guardarArchivo();
	system("clear");
	liberarMemoria();
	system("clear");
	return 0;
}

// 	Funcion para imprimir la informacion de un peleador en pantalla.

void imprimirPeleador(struct peleador pel, int i){
	int j, nom=1;
	printf("%3d ", i);

	// 	Este ciclo imprime el nombre del peleador, de una manera que siempre ocupe 20 caracteres,
	// ocupamos un ciclo en vez de un %20s ya que de esta manera los nombres se alinean hacia la
	// izquierda en vez de la derecha, y tambien si es que el nombre excede los 20 caracteres, solo
	// se imprimiran sus primeros 20 caracteres, para conservar el orden de la lista desplegada.

	for(j=0;j<20;++j){
		if(pel.nombre[j]=='\0'){
			nom=0;
		}
		if(nom){
			printf("%c", pel.nombre[j]);
		}
		else{
			printf(" ");
		}
	}
	printf(" %d\t%.2lf\t%.2lf\t", pel.edad, pel.peso,pel.estatura);
	if(pel.estilo==1){
		printf("Boxeo       ");
	}
	else if(pel.estilo==2){
		printf("Kick Boxing ");
	}
	else if(pel.estilo==3){
		printf("MMA         ");
	}
	printf("\t%d\t \t%d\n", pel.ganadas, pel.perdidas);
}

// Funcion que retorna el numero de peleadores almacenados hasta el momento en la lista.

int largo(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	current=head;
	int len;
	for(len=0;current!=NULL;++len){
		current=current->next;
	}
	return len;
}

// 	Funcion para agregar un peleador a la lista, primero se busca el lugar que debe estar
// el peleador, luego se agrega el peleador en un nodo entre los dos nodos que deberia estar,
// conservando el orden.

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

// 	Funcion para desplegar la lista, simplemente para cada peleador lo imprimimos
// con la funcion imprimirPeleador, a medida que avanzamos por la lista.

void desplegarLista(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	if(current==NULL){
		printf("ERROR al reservar memoria.\n");
	}
	current=head;
	int i=1;
	printf(" ID NOMBRE\t\t EDAD\tPESO\tEST.\tESTILO\t\tVICTORIAS\tDERROTAS\n");
	while(current!=NULL){
		imprimirPeleador(current->peleador, i);
		current=current->next;
		++i;
	}
}

// 	Funcion para desplegar por peso, esta funcion recive un valor que se traduce
// como la categoria de peso escogida por el usuario, luego imprimimos solo los,
// peleadores correspondientes a esta categoria de peso.

void desplegarPorPesos(int catPeso){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	if(current==NULL){
		printf("ERROR al reservar memoria.\n");
	}
	current=head;
	double limInf, limSup;
	int i=1;
	printf(" ID NOMBRE\t\t EDAD\tPESO\tEST.\tESTILO\t\tVICTORIAS\tDERROTAS\n");
	if(catPeso==1){
		limInf=0;
		limSup=69.99;
	}
	else if(catPeso==2){
		limInf=69.99;
		limSup=76.99;
	}
	else if(catPeso==3){
		limInf=76.99;
		limSup=83.99;
	}
	else if(catPeso==4){
		limInf=83.99;
		limSup=92.99;
	}
	else if(catPeso==5){
		limInf=92.99;
		limSup=8000000;
	}
	while(current!=NULL){
		if(current->peleador.peso > limSup){
			break;
		}
		if(current->peleador.peso > limInf){
			imprimirPeleador(current->peleador, i);
		}
		current=current->next;
		++i;
	}
}

// 	Funcion para desplegar la lista por categoria de estilos, funciona muy parecido a la 
// de categoria de peso.

void desplegarPorEstilos(int estilo){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	if(current==NULL){
		printf("ERROR al reservar memoria.\n");
	}
	current=head;
	int i=1;
	printf(" ID NOMBRE\t\t EDAD\tPESO\tEST.\tESTILO\t\tVICTORIAS\tDERROTAS\n");
	while(current!=NULL){
		if(current->peleador.estilo >= estilo){
			imprimirPeleador(current->peleador, i);
		}
		current=current->next;
		++i;
	}
}

// 	Esta funcion lee un archivo de una manera especifica, la cual es igual a la manera en la que se guarda.

void leerArchivo(){
	FILE *archivo=NULL;
	archivo=fopen("datos.txt", "r");
	printf("Leyendo archivo...\n");
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

// 	Se guarda en el archivo los datos de manera ordenada (Por el peso).

void guardarArchivo(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	FILE *archivo=NULL;
	archivo=fopen("datos.txt", "w");
	printf("Guardando datos...\n");
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

// 	Elimina un peleador especifico de la lista desplegada (Por ID), y se libera la memoria del peleador
// eliminado.

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
	else{
		prev->next=current->next;
		free(current);
	}
}

// 	Se ocupa para modificar un dato especifico de un elemento especifico de la lista, esta funcion
// retorna un 1 si el usuario se equivoco de peleador o si se arrepintio de editar el peleador seleccionado,
// si es que no, retorna 0.

int modificar(int id){
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
	printf(" ID NOMBRE\t\t EDAD\tPESO\tEST.\tESTILO\t\tVICTORIAS\tDERROTAS\n");
	imprimirPeleador(current->peleador, ID);
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
		return 1;
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
	return 0;
}

// Libera la memoria de toda la lista.

void liberarMemoria(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	printf("Liberando memoria...\n");
	while(head!=NULL){
		current=head->next;
		free(head);
		head=current;
	}
}

// Se ocupa para que algunos mensajes no desaparezcan.

void presioneEnterParaContinuar(){
	printf("\nPresione Enter para continuar...\n");
	getchar();
	getchar();
}