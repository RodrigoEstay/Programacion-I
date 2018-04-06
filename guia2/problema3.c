#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, k, min, max, temp;
	do{
		printf("Ingrese un numero MAYOR QUE 0:\n");
		scanf("%d", &n);
	}while(n<=0);
	int orig[n];
	printf("Ingrese los %d numeros:\n", n);
	for(i=0;i<n;++i)
		scanf("%d", &orig[i]);
	for(i=0;i<n/2;++i){
		for(k=i, min=i, max=i;k<n-i;++k){
			if(orig[k]>orig[max])
				max=k;
			if(orig[k]<orig[min])
				min=k;
			}
			temp=orig[min];
			orig[min]=orig[i];
			orig[i]=temp;
			temp=orig[max];
			orig[max]=orig[n-1-i];
			orig[n-1-i]=temp;
			printf("%d\t%d\n", orig[min], orig[max]);
	}
	printf("En orden:\n");
	for(i=0;i<n;++i)
		printf("%d ", orig[i]);
	printf("\n");
	return 0;
}
