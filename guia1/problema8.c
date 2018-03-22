#include <stdlib.h>
#include <stdio.h>

int main (){
	int num;
	printf("Ingrese un numero entre 1 y 10:\n");
	scanf("%d", &num);
	if(num<=0 || num>10){
		printf("ERROR NUMERO INGRESADO INVALIDO, PROGRAMA TERMINADO.\n");
		return 0;
	}
	else if(num==10)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==9)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==8)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==7)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==6)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==5)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==4)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==3)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==2)
		printf("paranguacutilimicuaro\nparanguacutilimicuaro\n");
	else if(num==1)
		printf("paranguacutilimicuaro\n");
	return 0;
}