#include <stdio.h>
#include <stdlib.h>

/* Revisamos en cada numero del 2 al 10 si es divisor, si lo es, lo mimprime. */

int main (){
	int num;
	printf("Ingrese un numero:\n");
	scanf("%d", &num);
	printf("Divisores entre 2 y 10:\n");
	if(num%2==0)
		printf("2 ");
	if(num%3==0)
		printf("3 ");
	if(num%4==0)
		printf("4 ");
	if(num%5==0)
		printf("5 ");
	if(num%6==0)
		printf("6 ");
	if(num%7==0)
		printf("7 ");
	if(num%8==0)
		printf("8 ");
	if(num%9==0)
		printf("9 ");
	if(num%10==0)
		printf("10 ");
	printf("\n");
	return 0;
}