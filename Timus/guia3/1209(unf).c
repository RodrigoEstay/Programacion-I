#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, num, i;
	scanf("%d", &N);
	while(N--){
		i=1;
		scanf("%d", &num);
		while(num>0){
			num-=i;
			++i;
		}
		if(num+i-1==1){
			printf("1");
		}
		else{
			printf("0");
		}
		if(N!=0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	return 0;
}