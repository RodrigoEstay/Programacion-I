#include <stdio.h>
#include <stdlib.h>

/* Se saca el area (A*B) luego se multiplica por la cantidad de paneles (*N)
luego se multiplica por 2 ya que se debe aplicar el proceso por los dos lados
de los paneles. */

int main (){
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	printf("%d\n", A*B*N*2);
	return 0;
}