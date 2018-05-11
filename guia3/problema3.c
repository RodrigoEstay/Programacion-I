#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Programa hecho sin ayuda. */

int main (){
	int n, i, j, exp=0;
	scanf("%d",&n);
	double num[n], sum=0, temp, prom, desvM=0, var=0;
	for(i=0;i<n;++i){
		scanf("%lf", &num[i]);
	}
	/* Ordenamos el arreglo de mayor a menor. (mientras sumamos todos los numeros)*/
	for(i=0;i<n;++i){
		for(j=i;j<n;++j){
			if(num[i]<num[j]){
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
		sum+=num[i];
	}
	/* Mientras el menor no se encuentre entre 10 y 1 significa que aun no esta en notacion
	cientifica, asi que dividimos el numero por 10 si es mayor a 10 y le sumamamos 1 al exponente,
	si no, lo dividimos por 10 y le restamos 1 al exponente si el numero es mayor a 1. */
	while(!(fabs(num[0])<10 && fabs(num[0])>1)){
		if(fabs(num[0])>10){
			num[0]/=10;
			exp++;
		}
		else if(fabs(num[0])<1){
			num[0]*=10;
			exp--;
		}
		printf("%lf\n", num[0]);
	}
 	/* Calculamos el promedio, y las sumas de la desviacion media y varianza sin
 	dividir, luego los dividimos. */
	prom=sum/n;
	for(i=0;i<n;++i){
		desvM=desvM+fabs(num[i]-prom);
		var=var+pow((num[i]-prom),2);
	}
	desvM/=n;
	var/=n;
	/* Hay que notar que la desviacion estandar es la raiz cuadrada de la varianza. */
	printf("El minimo: %lfx10^%d\n", num[0], exp);
	printf("El maximo: %+10lf\n", num[n-1]);
	printf("La media: %.8lf\n", prom);
	printf("La mediana: %.4lf\n", (n%2==0)?((num[n/2]+num[n/2-1])/2):(num[n/2]));
	printf("La desviacion media: %.2lf\n", desvM);
	printf("La desviacion estandar: %.3lf\n", sqrt(var));
	printf("La varianza: %lf\n", var);
	return 0;
}