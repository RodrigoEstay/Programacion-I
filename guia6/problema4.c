#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Programa hecho sin ayuda

void mergeSort(int *v, int tam);
void merge(int* v1, int* v2, int tam1, int tam2);

// 	Este main es para probar las funciones, lo que se hace es que se le pide al usuario un numero n, luego
// se generan n vectores de tamanos aleatorios entre 1 y 50, luego se llenan con valores aleatorios entre
// 0 y 149, se imprime el vector, luego se ordena con la funcio mergeSort, una vez ordenado se vuelve a
// imprimir el vector, pero si es que se encuentra que no esta ordenado de menor a mayor se imprime un grito.
int main(){
	int n, i, tam;
	srand(time(NULL));
	scanf("%d", &n);
	while(n--){
		tam=rand()%50+1;
		int *arr=(int*)malloc(tam*sizeof(int));
		for(i=0;i<tam;++i){
			*(arr+i)=rand()%150;
		}
		for(i=0;i<tam;++i){
			printf("%d ", *(arr+i));
		}
		printf("\n");
		mergeSort(arr, tam);
		for(i=0;i<tam;++i){
			if(i){
				if(*(arr+i-1) > *(arr+i)){
					printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHH\n");
				}
			}
			printf("%d ", *(arr+i));
		}
		printf("\n\n");
		free(arr);
	}
	return 0;
}

// 	Esta funcion divide el vector en 2, y luego se envian sus dos partes a esta misma
// funcion, luego se combinan con merge.
void mergeSort(int *v, int tam){
	if(tam==1){
		return;
	}
	mergeSort(v, tam-tam/2);
	mergeSort(v+(tam-tam/2), tam/2);
	merge(v, v+(tam-tam/2), tam-tam/2, tam/2);
}

// 	Esta funcion combina los vectores v1 y v2 de manera que se mantenga el orden de menor
// a mayor. Hay que notar que esta funcion considera que los vectores v1 y v2 ya estaban
// ordenados de menor a mayor.
void merge(int* v1, int* v2, int tam1, int tam2){
	int n=tam1, m=tam2, i;
	int *v=(int*)malloc((n+m)*sizeof(int));
	// 	Vamos comparando los primeros valores de v1 y v2, y el menor de estos
	// lo colocamos en v.
	while(n && m){
		if(*(v1+(tam1-n)) > *(v2+(tam2-m))){
			*(v+(tam2+tam1-n-m))=*(v2+(tam2-m));
			--m;
		}
		else{
			*(v+(tam2+tam1-n-m))=*(v1+(tam1-n));
			--n;
		}
	}
	// 	Se implementan los valores restantes de v1 en v
	// (este ciclo solo se inicia si se acabaron los valores de v2).
	while(n){
		*(v+(tam2+tam1-n-m))=*(v1+(tam1-n));
		--n;
	}
	// 	Se implementan los valores restantes de v2 en v
	// (este ciclo solo se inicia si se acabaron los valores de v1).
	while(m){
		*(v+(tam2+tam1-n-m))=*(v2+(tam2-m));
		--m;
	}
	// 	Como sabemos que v1 y v2 componen las mitades de un vector original de tal manera
	// que la primera mitad y la segunda son v1 y v2 respectivamente, entonces igualamos los 
	// valores de v1 a la primera mitad del vector con los valores ordenados (v), y la segunda
	// mitad a v2, de esta manera se ordena el vector original.
 	for(i=0;i<tam1;++i){
		*(v1+i)=*(v+i);
	}
	for(i=0;i<tam2;++i){
		*(v2+i)=*(v+tam1+i);
	}
	free(v);
}