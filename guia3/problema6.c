#include <stdio.h>
#include <stdlib.h>
/* Programa hecho sin ayuda.

Escaneamos el numero de punto flotante como un string, ya que asi es mas simple,
luego mientras avanzamos por el string, y para cada numero lo sumamos a "sum", si
encontramos un caracter que no es un numero o mas de un punto, significa que no se 
ingreso un numero de punto flotante correcto, asi que mandamos un error. */ 

int main(){
	char num[250], isPoint=1;
	int sum=0, i;
	scanf("%s", num);
	for(i=0;num[i]!='\0';++i){
		if(num[i]>='0' && num[i]<='9'){
			sum+=(num[i]-'0');
		}
		else{
			if(num[i]!='.' || !isPoint){
				printf("Numero ingresado invalido.\n");
				return 0;
			}
			isPoint--;
		}
	}
	printf("%d\n", sum);
	return 0;
}