#include <stdlib.h>
#include <stdio.h>

// TODO: ORDENAMIENTO NO FUNCIONA (o almenos eso parece, podria ser error de lectura del archivo tambien).
// TODO: Los informes de errores de alocacion de memoria y de abrir archivos, de momento imprimen un mensaje
//		que se borra instantaneamente o simplemente no pasa nada, arreglar esto, que los errores se hagan notar.

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

struct nodo *head = NULL;
struct nodo *current = NULL;

int largo();
void agregar(struct peleador pel);
void desplegarLista();
void ordenar();
void leerArchivo();
void guardarArchivo();
void presioneEnterParaContinuar();

int main(){
	leerArchivo();
	//ordenar();
	int user;
	while(1){
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
		while(user>7 && user<1){
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
		if(user==1){
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
			//ordenar();
		}
		else if(user==2){
			
		}
		else if(user==3){
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
		else if(user==7){
			system("clear");
			break;
		}
	}
	guardarArchivo();
	return 0;
}

int largo(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	current=head;
	int len;
	for(len=0;current!=NULL;++len){
		current=current->next;
	}
	return len;
}

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

void ordenar(){
	struct nodo *current=(struct nodo*)malloc(sizeof(struct nodo));
	struct nodo *next=(struct nodo*)malloc(sizeof(struct nodo));
	struct peleador temp;
	if(current==NULL || next==NULL){
		printf("ERROR al reservar memoria.\n");
	}
	int i, j, len=largo();
	for(i=1;i<len;++i){
		current=head;
		next=head->next;
		for(j=i+1;j<len;++j){
			if(current->peleador.peso>next->peleador.peso){
				temp=current->peleador;
				current->peleador=next->peleador;
				next->peleador=temp;
			}
			current=current->next;
			next=next->next;
		}
	}
}

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

void presioneEnterParaContinuar(){
	printf("\nPresione Enter para continuar...\n");
	getchar();
	getchar();
}