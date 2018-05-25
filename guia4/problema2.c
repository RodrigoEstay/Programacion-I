#include <stdio.h>
#include <stdlib.h>

/* Codigo hecho sin ayuda*/

double operacion(char op, double v1, double v2); // Declaramos la funcion.

int main(){
	double v1, v2;
	char op;
	printf("Ingrese op, v1 y v2.\n");
	scanf("%c %lf %lf", &op, &v1, &v2);
	while((op!='+' && op!='-' && op!='*' && op!='/') || (op=='/' && v2==0)){ // Validamos la entrada.
		if((op=='/' && v2==0)){
			printf("No se puede dividir por 0. Reingrese todos los valores.\n");
		}
		else{
			printf("Operacion invalida. Reingrese todos los valores.\n");
		}
		scanf("%c %lf %lf", &op, &v1, &v2);
	}
	printf("%lf\n", operacion(op,v1,v2));
	return 0;
}

/* Observamos de cual operacion se trata y retornamos el valor esperado. */

double operacion(char op, double v1, double v2){
	if(op=='+'){
		return v1+v2;
	}
	else if(op=='-'){
		return v1-v2;
	}
	else if(op=='*'){
		return v1*v2;
	}
	else if(op=='/'){
		return v1/v2;
	}
}