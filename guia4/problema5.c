#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double operacion(char op, double v1, double v2);
long long mcm(long long n1, long long n2);
long long mcd(long long n1, long long n2);

int main(){
	double v1, v2;
	long long n1, n2;
	char user1[100], op;
	int user2, exit=0;
	while(1){
		printf("Bienvenido. Seleccione la operacion a realizar:\n"
		"operacion\t- Realizar suma, resta, multiplicacion o division entre dos valores.\n"
		"mcm\t- Calcular el minimo comun multiplo de dos numeros.\n"
		"mcd\t- Calcular el maximo comun divisor de dos numeros.\n"
		"salir\t- Salir del programa.\n");
		scanf("%s", user1);
		if(!strcmp(user1,"operacion")){
			while(1){
				printf("En esta funcion debe ingresar una operacion y 2 valores cualquiera, siempre y"
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
					exit=1;
					break;
				}
				else if(user2==2){	
					break;
				}
				else{
					//TODO: limpiar pantalla
				}
			}
			if(exit){
				break;
			}
		}
		else if(!strcmp(user1,"mcm")){
			while(1){
				printf("En esta funcion debe ingresar, separados por un espacio, dos numeros naturales, "
				"excluyendo el 0, y luego se le entregara el valor del minimo comun multiplo de " 
				"los numeros ingresados.\n\n"
				"1- Ingresar operacion.\n"
				"2- Volver al menu principal.\n");
				scanf("%d", &user2);
				if(user2==1){
					printf("Ingrese los valores como se especifico anteriormente.\n");
					scanf("%lld%lld", &n1, &n2);
					while(n1<=0 || n2<=0){
						printf("Entrada invalida. Porfavor compruebe que los numeros sean naturales distintos de 0.\n");
						scanf("%lld%lld", &n1, &n2);
					}
					printf("El minimo comun multiplo de %lld y %lld es %lld\n", n1, n2, mcm(n1,n2));
					exit=1;
					break;
				}
				else if(user2==2){	
					break;
				}
				else{
					//TODO: limpiar pantalla
				}
			}
			if(exit){
				break;
			}
		}
		else if(!strcmp(user1,"mcd")){
			while(1){
				printf("En esta funcion debe ingresar, separados por un espacio, dos numeros enteros"
				"distintos de 0, y luego se le entregara el valor del maximo comun divisor de los numeros "
				"ingresados.\n\n"
				"1- Ingresar operacion.\n"
				"2- Volver al menu principal.\n");
				scanf("%d", &user2);
				if(user2==1){
					printf("Ingrese los valores como se especifico anteriormente.\n");
					scanf("%lld%lld", &n1, &n2);
					while(n1<=0 || n2<=0){
						printf("Entrada invalida. Porfavor compruebe que los numeros sean enteros distintos de 0.\n");
						scanf("%lld%lld", &n1, &n2);
					}
					printf("El maximo comun divisor de %lld y %lld es %lld\n", n1, n2, mcd(n1,n2));
					exit=1;
					break;
				}
				else if(user2==2){	
					break;
				}
				else{
					//TODO: limpiar pantalla
				}
			}
			if(exit){
				break;
			}
		}
		else if(!strcmp(user1,"salir")){
			break;
		}
		else{
			//TODO: limpiar pantalla.
		}
	}
	return 0;
}

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