#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char a[100];
	scanf("%s", a);
	char* b=strtok(a,"+");
	while(b!=NULL){
		printf("%s\n", b);
		b=strtok(NULL,"+");
	}
	return 0;
}