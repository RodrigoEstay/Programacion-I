#include <stdlib.h>
#include <stdio.h>

int main (){
	int num1, num2, num3;
	printf("Introduzca 3 numeros:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	if (num1<0 && num2<0 && num3<0)
		printf("todos\n");
	if (num1>0 && num2>0 && num3>0)
		printf("ninguno\n");
	if (num1>0 && num2<0 && num3<0)
		printf("al menos dos\n");
	if (num1<0 && num2>0 && num3<0)
		printf("al menos dos\n");
	if (num1<0 && num2<0 && num3>0)
		printf("al menos dos\n");
	if (num1>0 && num2>0 && num3<0)
		printf("al menos uno\n");
	if (num1<0 && num2>0 && num3>0)
		printf("al menos uno\n");
	if (num1>0 && num2<0 && num3>0)
		printf("al menos uno\n");
	return 0;
}