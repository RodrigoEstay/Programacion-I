#include <stdio.h>
#include <stdlib.h>

int main(){
	long long int N, num, i, form;
	scanf("%lld", &N);
	while(N--){
		form=1;
		scanf("%lld", &num);
		for(i=1;num>form;++i){
			form=1+(i*(i+1))/2;
		}
		if(num==form){
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
