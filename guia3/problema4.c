#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;
	printf("Ingrese un caracter:\n");
	scanf("%c", &c);
	if(c>='a' && c<='z'){
		printf("minuscula\n");
	}
	else if(c>='A' && c<='Z'){
		printf("mayuscula\n");
	}
	else if(c>='0' && c<='9'){
		printf("numero\n");
	}
	else{
		printf("otro\n");
	}
	return 0;
}