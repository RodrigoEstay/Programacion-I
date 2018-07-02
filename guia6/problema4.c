#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i;
	scanf("%d", &n);
	int *arr=(int*)malloc(n*sizeof(int*));
	for(i=0;i<n;++i){
		scanf("%d", (v+i));
	}
	mergeSort(arr,n);
	for(i=0;i<n;++i){
		printf("%d", *(v+i));
	}
	printf("\n");
	free(arr);
	return 0;
}

void mergeSort(int *v, int tam){
	if(tam==1){
		return;
	}
	mergeSort(v, tam-tam/2);
	mergeSort(v+tam/2, tam/2);
	merge(v, v+tam/2, tam-tam/2, tam/2);
}

void merge(int* v1, int* v2, tam1, tam2){
	int n=tam1, m=tam2;
	while(n && m){
		if(*(v1+(tam1-n))>*(v2+(tam2-m))){
			
		}
	}
}

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}