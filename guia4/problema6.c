#include <stdio.h>
#include <stdlib.h>

void ordenParcial(int* v1, int n, int cant);

int main(){
	int n;
	scanf("%d", &n);
	int v1[n], i, cant;
	for(i=0;i<n;++i){
		scanf("%d", &v1[i]);
	}
	scanf("%d", &cant);
	for(i=0;i<n;++i){
		printf("%d ", v1[i]);
	}
	printf("\n");
	ordenParcial(v1, n, cant);
	for(i=0;i<n;++i){
		printf("%d ", v1[i]);
	}
	printf("\n");
	return 0;
}

void ordenParcial(int* v1, int n, int cant){
	int i, j, temp;
	for(i=0;i<n-1;++i){
		for(j=i;j<n;++j){
			if(v1[i]<v1[j]){
				temp=v1[j];
				v1[j]=v1[i];
				v1[i]=temp;
			}
		}
	}
	for(i=0;i<cant/2;++i){
		temp=v1[i];
		v1[i]=v1[cant-i-1];
		v1[cant-i-1]=temp;
	}
}