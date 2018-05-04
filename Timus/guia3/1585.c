#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n, countType[3]={0,0,0};
	scanf("%d", &n);
	char penguin[10], type[15], types[3][14]={"Little", "Macaroni", "Emperor"};
	while(n--){
		scanf("%s %s", type, penguin);
		if(!strcmp(type,types[0])){
			countType[0]+=1;
		}
		else if(!strcmp(type,types[1])){
			countType[1]+=1;
		}
		else if(!strcmp(type,types[2])){
			countType[2]+=1;
		}
	}
	int max=0;
	for(n=0;n<3;++n){
		if(countType[max]<countType[n]){
			max=n;
		}
	}
	printf("%s Penguin\n", types[max]);
	return 0;
}