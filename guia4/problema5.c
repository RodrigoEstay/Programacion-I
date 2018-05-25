#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Programa hecho sin ayuda. */

double operacion(char op, double v1, double v2);
long long mcm(long long n1, long long n2);
long long mcd(long long n1, long long n2);

int main(){
	double v1, v2;
	long long n1, n2;
	char user1[100], op, c; // "user1" es la primera eleccion del usuario.
	int user2; // "user2" es la segunda eleccion del usario.
	while(1){ // Este while es para imprimir el menu denuevo si se da una entrada invalida.
		system("clear");
		user2=0; // Hacemos que sea 0, para que al entrar a algun if no se eecute algo no deseado.
		printf("Bienvenido. Seleccione la operacion a realizar:\n"
		"operacion\t- Realizar suma, resta, multiplicacion o division entre dos valores.\n"
		"mcm\t- Calcular el minimo comun multiplo de dos numeros.\n"
		"mcd\t- Calcular el maximo comun divisor de dos numeros.\n"
		"salir\t- Salir del programa.\n");
		scanf("%s", user1);

		/* Comparamos lo escrito por el usuario con cada posible opcion y ejecutamos lo que hace,
		si no volvemos a iprimir el menu. */

		if(!strcmp(user1,"operacion")){
			while(1){ // Este while es para imprimir el submenu denuevo.
				system("clear");
				getchar();
				printf("Operacion\n\n"
				"En esta funcion debe ingresar una operacion y 2 valores cualquiera, siempre y"
				"cuando se le puedan aplicar la operacion escogida, la operacion y los valores deben"
				"estar separados por un espacio. Las operaciones aceptadas son:\n"
				"+ para sumar.\n- para restar\n* para multiplicar\n/ para dividir.\n"
				"Note que la operacion se realiza de la manera (primer valor) (operacion) (segundo valor).\n\n"
				"1- Ingresar operacion.\n"
				"2- Volver al menu principal.\n");
				scanf("%d", &user2);
				if(user2==1){
					printf("Ingrese los valores como se especifico anteriormente.\n");
					getchar();
					scanf("%c %lf %lf", &op, &v1, &v2);
					// Validamos la entrada.
					while((op!='+' && op!='-' && op!='*' && op!='/') || (op=='/' && v2==0)){
						if((op=='/' && v2==0)){
							printf("No se puede dividir por 0. Reingrese todos los valores.\n");
						}
						else{
							printf("Operacion invalida. Reingrese todos los valores.\n");
						}
						scanf("%c %lf %lf", &op, &v1, &v2);
					}
					printf("%.3lf %c %.3lf = %.3lf\n", v1, op, v2, operacion(op,v1,v2));
					printf("\nPresione una tecla para continuar...\n");
					break;
				}
				else if(user2==2){	
					break;
				}
				else{ // Para entrada invalida, limpiamos la pantalla y el while imprimira el submenu denuevo.
					system("clear");
				}
			}
		}
		else if(!strcmp(user1,"mcm")){
			while(1){ // Este while es para imprimir el submenu denuevo.
				system("clear");
				getchar();
				printf("Minimo comun multiplo\n\n"
				"En esta funcion debe ingresar, separados por un espacio, dos numeros naturales, "
				"excluyendo el 0, y luego se le entregara el valor del minimo comun multiplo de " 
				"los numeros ingresados.\n\n"
				"1- Ingresar operacion.\n"
				"2- Volver al menu principal.\n");
				scanf("%d", &user2);
				if(user2==1){
					printf("Ingrese los valores como se especifico anteriormente.\n");
					scanf("%lld%lld", &n1, &n2);
					// Validamos la entrada.
					while(n1<=0 || n2<=0){
						printf("Entrada invalida. Porfavor compruebe que los numeros sean naturales distintos de 0.\n");
						scanf("%lld%lld", &n1, &n2);
					}
					printf("El minimo comun multiplo de %lld y %lld es %lld\n", n1, n2, mcm(n1,n2));
					printf("\nPresione una tecla para continuar...\n");
					break;
				}
				else if(user2==2){	
					break;
				}
				else{ // Para entrada invalida, limpiamos la pantalla y el while imprimira el submenu denuevo.
					system("clear");
				}
			}
		}
		else if(!strcmp(user1,"mcd")){
			while(1){ // Este while es para imprimir el submenu denuevo.
				system("clear");
				getchar();
				printf("Maximo comun divisor\n\n"
				"En esta funcion debe ingresar, separados por un espacio, dos numeros enteros"
				"distintos de 0, y luego se le entregara el valor del maximo comun divisor de los numeros "
				"ingresados.\n\n"
				"1- Ingresar operacion.\n"
				"2- Volver al menu principal.\n");
				scanf("%d", &user2);
				if(user2==1){
					printf("Ingrese los valores como se especifico anteriormente.\n");
					scanf("%lld%lld", &n1, &n2);
					// Validamos la entrada.
					while(n1<=0 || n2<=0){
						printf("Entrada invalida. Porfavor compruebe que los numeros sean enteros distintos de 0.\n");
						scanf("%lld%lld", &n1, &n2);
					}
					printf("El maximo comun divisor de %lld y %lld es %lld\n", n1, n2, mcd(n1,n2));
					printf("\nPresione una tecla para continuar...\n");
					break;
				}
				else if(user2==2){	
					break;
				}
				else{ // Para entrada invalida, limpiamos la pantalla y el while imprimira el submenu denuevo.
					system("clear");
				}
			}
		}
		// Si se escoje salir, salimos del while, lo cual nos lleva al return 0; 
		else if(!strcmp(user1,"salir")){
			break;
		}
		else{ // Para entrada invalida, limpiamos la pantalla y el while imprimira el submenu denuevo.
			system("clear");
		}
	}
	return 0;
}

/* Estas son las funciones explicadas previamente. */

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

long long mcm(long long n1, long long n2){
	long long temp, i;
	if(n2>n1){
		temp=n1;
		n1=n2;
		n2=temp;
	}
	for(i=n1;i%n1!=0 || i%n2!=0;++i){}
	return i;
}

long long mcd(long long n1, long long n2){
	long long temp, i;
	if(n1>n2){
		temp=n2;
		n2=n1;
		n1=temp;
	}
	i=n1;
	while(1){
		if(i==0){
			break;
		}
		if(n1%i==0 && n2%i==0){
			break;
		}
		--i;
	}
	return i;
}