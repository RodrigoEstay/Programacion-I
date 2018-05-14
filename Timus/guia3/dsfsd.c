#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[100]="hola", s[2]="+", *t;
	t=strtok(str, s);
	do{
		printf("%s\n", t);
		t=strtok(NULL,s);
	}while(t!=NULL);
	return 0;
}