#include <stdlib.h>
#include <stdio.h>

struct peleador{
	char nombre[100];
	int peso;
	int edad;
	int estatura;
	int estilo;
	int ganadas;
	int perdidad;
}

struct nodo{
	struct peleador peleador;
	struct nodo *next;
}

struct node *head = NULL;
struct node *current = NULL;

int main(){
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

		}
		else if(user==2){
			
		}
		else if(user==3){
			
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
	return 0;
}