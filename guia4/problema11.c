#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, j;
	printf("Tamaño?\n");
	scanf("%d", &n);
	printf("Ingrese los %d valores\n", n*n);
	char mat[n][n];
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%c", &mat[i][j]);
		}
	}
	printf("la palabra mas larga es de %d letras.\n", longitudPalabraMasLarga(n,mat));
	return 0;
}

int longitudPalabraMasLarga(int n, char crucigrama[n][n]){
	int i, j, cont1, cont2, maxLen=0;
	for(i=0;i<n;++i){
		cont1=0;
		cont2=0;
		for(j=0;j<n;++j){
			if(crucigrama[i][j]=='-'){
				if(cont1>maxLen){
					maxLen=cont1;
				}
				cont1=0;
			}
			else{
				++cont1;
			}
			if(crucigrama[j][i]=='-'){
				if(cont2>maxLen){
					maxLen=cont2;
				}
				cont2=0;
			}
			else{
				++cont2;
			}
		}
		if(cont1>maxLen){
			maxLen=cont1;
		}
		if(cont2>maxLen){
			maxLen=cont2;
		}
	}
	return maxLen;
}