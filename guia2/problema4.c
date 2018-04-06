#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i, n, comp=0;
	printf("Ingrese un numero entero:\n");
	scanf("%d", &n);
	if(n<0)
		n=abs(n);
	if(n==0 || n==1){
		printf("No es ni primo ni compuesto.\n");
		return 0;
	}
	for(i=2;i<sqrt(n);++i){
		if(n%i==0){
			printf("Es compuesto.\n");
			return 0;
		}
	}
	printf("Es primo.\n");
	return 0;
}
