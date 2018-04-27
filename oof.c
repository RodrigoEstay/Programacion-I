#include <stdio.h>
#include <stdlib.h>

int main (){
	int n, m, cont=1, start=0;
	scanf("%d%d", &n, &m);
	int mat[n][m], i, j;
	while(1){
		for(i=start;i<m-start;++i,++cont){
			mat[start][i]=cont;
		}
		if(cont==n*m+1){
			break;
		}
		for(i=start+1;i<n-start;++i,++cont){
			mat[i][m-1-start]=cont;
		}
		if(cont==n*m+1){
			break;
		}
		for(i=m-start-2;i>=start;--i,++cont){
			mat[n-start-1][i]=cont;
		}
		if(cont==n*m+1){
			break;
		}
		for(i=n-start-2;i>start;--i,++cont){
			mat[i][start]=cont;
		}
		if(cont==n*m+1){
			break;
		}
		++start;
	}
	printf("\n");
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}